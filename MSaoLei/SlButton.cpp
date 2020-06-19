#include "SlButton.h"
#include <QDebug>
SlButton::SlButton()
{
	mState = unclick;
	mType = unknow;
	connect(this, SIGNAL(clicked()),this,SLOT(clickedSlots()));
	connect(this, SIGNAL(pressed()), this, SLOT(pressSlots()));
	LeftPressed = 0;
	RightPressed = 0;
	IsBothPressed = 0;
	groundMineNum = 0;
}

SlButton::~SlButton()
{

}

void SlButton::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::RightButton)
	{
		RightPressed = 1;
	}
	if (event->button()==Qt::LeftButton)
	{
		LeftPressed = 1;
	}
	HandleMousePress();
	QPushButton::mousePressEvent(event);
}

void SlButton::mouseReleaseEvent(QMouseEvent *event)
{
	if (event->button() == Qt::RightButton)
	{
		RightPressed = 0;
	}
	if (event->button() == Qt::LeftButton)
	{
		LeftPressed = 0;
	}
	if (IsBothPressed&&RightPressed==0&& LeftPressed==0)
	{
		IsBothPressed = 0;
		qDebug() << QString::number(X) + " " + QString::number(Y) + " emit right and left release signal";
		emit emitRightAndLeftRelease();
	}
	QPushButton::mouseReleaseEvent(event);
}

void SlButton::HandleMousePress()
{
	if (LeftPressed&&RightPressed)
	{
		IsBothPressed = 1;
		qDebug() << QString::number(X) + " " + QString::number(Y) +" emit right and left signal";
		emit emitRightAndLeftPress();
	}
	else {
		if (RightPressed)
		{
			switch (mState)
			{
			case unclick:
				this->setStyleSheet("QPushButton{background-image:url(:/buttonType/redflag.png)}");
				qDebug() << QString::number(X) + " " + QString::number(Y) + " emit right  signal";
				qDebug() << "unclick to mark";
				this->mState = mark;
				emit emitRightClicked();
				break;
			case State::clicked:
				break;
			case question:
				this->setStyleSheet("QPushButton{background-image:url(:/buttonType/unknow.jpg)}");
				qDebug() << QString::number(X) + " " + QString::number(Y) + " emit right  signal";
				this->mState = unclick;
				qDebug() << "question to unclick";
				emit emitRightClicked();
				break;
			case mark:
				this->setStyleSheet("QPushButton{background-image:url(:/buttonType/question.png)}");
				qDebug() << QString::number(X) + " " + QString::number(Y) + " emit right  signal";
				this->mState = question;
				qDebug() << "mark to question";
				emit emitRightClicked();
				break;
			}
		}
	}
}

void SlButton::clickedSlots()
{
	//mState = State::clicked;
	qDebug() << QString::number(X)+" "+QString::number(Y)+" emit clicked signal";
	emit emitClickedSignals();
}

void SlButton::pressSlots()
{
	qDebug() << QString::number(X) + " " + QString::number(Y) + " emit press signal";
	emit emitbuttonPress();
}
