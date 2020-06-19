#include "MSaoLei.h"
#include <ctime>
#include <QDebug>
MSaoLei::MSaoLei(QWidget *parent)
    : QMainWindow(parent)
{
	saoleiing = 0;
    ui.setupUi(this);
	on_actionlow_triggered();
	connect(&timer, SIGNAL(timeout()),this,SLOT(timerSlot()));
	connect(this, SIGNAL(viurlClickblanksignal(int,int)), this, SLOT(viurlClickblankslot(int,int)));
	spendtime = 0;
	QPalette lcdpat = ui.lcdNumber_2->palette();
	lcdpat.setColor(QPalette::Normal, QPalette::WindowText, Qt::red);
	ui.lcdNumber_2->setPalette(lcdpat);
	QPalette lcdpat1 = ui.lcdNumber->palette();
	lcdpat1.setColor(QPalette::Normal, QPalette::WindowText, Qt::red);
	ui.lcdNumber->setPalette(lcdpat1);
	BoomPlay.setMedia(QUrl::fromLocalFile("boom.mp3"));
	BoomPlay.setVolume(30);
	ui.pushButton->setStyleSheet("QPushButton{background-image:url(:/buttonType/unknow.jpg)}");
}

void MSaoLei::CreateSaoLeiWidget(int XLength, int Ylength, int MineNum)
{
	CurrentMineNum = MineNum;
	RestMineNum = CurrentMineNum;
	CurrentXLength = XLength;
	CurrentYLength = Ylength;
	ui.tableWidget->setRowCount(XLength);
	ui.tableWidget->setColumnCount(Ylength);
	SetRestMine();
	for (int i=0;i<XLength;i++)
	{
		for (int j=0;j<Ylength;j++)
		{
			SlButton *button = new SlButton();
			buttonList.push_back(button);
			button->setStyleSheet("QPushButton{background-image:url(:/buttonType/unknow.jpg)}");
			button->SetPosition(i,j);
			connect(button, SIGNAL(emitClickedSignals()),this,SLOT(receiveButtonClicked()));
			connect(button, SIGNAL(emitRightClicked()), this, SLOT(receiveButtonRightClicked()));
			connect(button, SIGNAL(emitbuttonPress()), this, SLOT(recieveButtonPress()));
			connect(button, SIGNAL(emitRightAndLeftPress()), this, SLOT(receiveButttonRightAndLeftClicked()));
			connect(button, SIGNAL(emitRightAndLeftRelease()), this, SLOT(receiveButttonRightAndLeftRelease()));
			ui.tableWidget->setCellWidget(i,j, button);
		}
	}
	WidgetResize(XLength,Ylength);
	for (auto i: CreateMineList(MineNum, XLength, Ylength)) {
		SetMineButton(i);
	}

}

void MSaoLei::WidgetResize(int XLength, int Ylength)
{

	this->setFixedSize(Ylength * 35 + 27, XLength * 35 + 100);


//	ui.centralWidget->setGeometry(ui.centralWidget->geometry().x(), ui.centralWidget->geometry().y(), XLength*35+50,Ylength*35+20);
}

QList<int> MSaoLei::CreateMineList(int num, int X, int Y)
{
	QList<int> minelist;
	unsigned seed;
	seed = time(0);
	srand(seed);
	int cishu = num;
	for (int i = 1; i <= cishu; i++)
	{
		int currentdata = rand() %(X*Y) + 1;
		if (minelist.contains(currentdata))
		{
			cishu++;
		}
		else {
			minelist.push_back(currentdata);
		}

	}
	return minelist;
}

void MSaoLei::SetMineButton(int index)
{
	int row = index / CurrentYLength;
	int cloume = index % CurrentYLength;
	if (cloume==0)
	{
		row--;
		cloume = CurrentYLength;
	}
	SlButton *button =(SlButton* )ui.tableWidget->cellWidget(row, cloume-1);
	button->SetType(mine);
	minebuttonList.push_back(button);
}

int MSaoLei::GetMineNum(int row, int cloum)
{
	int num = 0;
	if (GetOneButtonType(row - 1, cloum - 1) == mine)
		num++;
	if (GetOneButtonType(row - 1, cloum) == mine)
		num++;
	if (GetOneButtonType(row - 1, cloum + 1) == mine)
		num++;
	if (GetOneButtonType(row, cloum - 1) == mine)
		num++;
	if (GetOneButtonType(row, cloum + 1) == mine)
		num++;
	if (GetOneButtonType(row + 1, cloum - 1) == mine)
		num++;
	if (GetOneButtonType(row + 1, cloum) == mine)
		num++;
	if (GetOneButtonType(row + 1, cloum + 1) == mine)
		num++;
	return num;
}

buttonType MSaoLei::GetOneButtonType(int row, int cloum)
{
	SlButton *button = (SlButton*)ui.tableWidget->cellWidget(row, cloum);
	if (button)
	{
		return button->GetType();
	}
	else {
		unknow;
	}

}

State MSaoLei::GetOneButtonState(int row, int cloum)
{
	SlButton *button = (SlButton*)ui.tableWidget->cellWidget(row, cloum);
	if (button)
	{
		return button->mState;
	}
	else {
		unclick;
	}
}

void MSaoLei::SetAllButtonDisable()
{
	for (auto index:buttonList)
	{
		if (index->GetType()== mine)
		{
			index->setStyleSheet("QPushButton{background-image:url(:/buttonType/mine.jpg)}");
		}
		index->setDisabled(true);
	}
}

void MSaoLei::SetRestMine()
{
	if (RestMineNum<0)
	{
		ui.lcdNumber->display(QString::number(0));
	}
	else {
		ui.lcdNumber->display(QString::number(RestMineNum));
	}

	if (RestMineNum == 0)
	{
		for (auto i : minebuttonList)
		{
		     if (i->mState!= mark)
		     {
				 return;
		     }
		}
		for (auto i : buttonList)
		{
			if (i->mState== unclick|| question)
			{
				return;
			}
		}
		timer.stop();
	}



}

QString MSaoLei::GetStyleSheetWithNum(int num)
{
	switch (num)
	{
	case 1:
		return QString("QPushButton{font: bold 30px;;color:rgb(0,0,255);}");
		break;
	case 2:
		return QString("QPushButton{font: bold 30px;color:rgb(0,255,0);}");
		break;
	case 3:
		return QString("QPushButton{font: bold 30px;color:rgb(255,0,0);}");
		break;
	case 4:
		return QString("QPushButton{font: bold 30px;color:rgb(85,85,255);}");
		break;
	case 5:
		return QString("QPushButton{font: bold 30px;color:rgb(170,85,0);}");
		break;
	case 6:
		return QString("QPushButton{font: bold 30px;color:rgb(255,85,255);}");
		break;
	case 7:
		return QString("QPushButton{font: bold 30px;color:rgb(170,0,0);}");
		break;
	case  8:
		return QString("QPushButton{font: bold 30px;color:rgb(0,0,0);}");
		break;
	}
}



void MSaoLei::SetBlankButtonGround(int X, int Y)
{
	if (X<0||Y<0||X>(CurrentXLength-1)||Y>(CurrentYLength-1))
	{
		return;
	}
	SlButton *pushButton = (SlButton *)ui.tableWidget->cellWidget(X , Y );
	pushButton->mState = State::clicked;

	if (pushButton->mType==unknow)
	{
		int num=GetMineNum(X, Y);
		if (num == 0)
		{
			pushButton->setStyleSheet("");
			pushButton->mType = blank;
			emit viurlClickblanksignal(X, Y);
			qDebug() << "blank reason" + QString::number(X) + " " + QString::number(Y) + " mState  clicked mType blank";
		}
		else {
			SlButton *pushButton = (SlButton *)ui.tableWidget->cellWidget(X, Y);
			pushButton->mType = mineground;
			pushButton->groundMineNum = num;
			pushButton->setText(QString::number(num));
			pushButton->setStyleSheet(GetStyleSheetWithNum(num));
			qDebug() << "blank reason" + QString::number(X) + " " + QString::number(Y) + " mState  clicked mType mineground";
		}
	}

}

void MSaoLei::SetButtonGroundShow(int X, int Y, bool isnormal)
{
	SetOneButtonShow(X - 1, Y - 1, isnormal);
	SetOneButtonShow(X - 1, Y, isnormal);
	SetOneButtonShow(X - 1, Y + 1, isnormal);
	SetOneButtonShow(X, Y - 1, isnormal);
	SetOneButtonShow(X, Y + 1, isnormal);
	SetOneButtonShow(X + 1, Y - 1, isnormal);
	SetOneButtonShow(X + 1, Y, isnormal);
	SetOneButtonShow(X + 1, Y + 1, isnormal);
}

void MSaoLei::SetOneButtonShow(int X, int Y, bool isnormal)
{
	if (X<0 || Y<0 || X>(CurrentXLength - 1) || Y>(CurrentYLength - 1))
	{
		return;
	}
	SlButton *pushButton = (SlButton *)ui.tableWidget->cellWidget(X, Y);
	State mState = pushButton->mState;
	switch (mState) 
	{
	case State::clicked:
		break;
	case question:
		break;
	case unclick:
	{
		if (pushButton->mType == unknow || mine)
		{
			if (isnormal)
			{
				pushButton->setStyleSheet("QPushButton{background-image:url(:/buttonType/unknow.jpg)}");

			}
			else {
				pushButton->setStyleSheet("QPushButton{background-image:url(:/buttonType/clicked.jpg)}");
			}
		}
	}
	case mark:
		break;
	}

}

int MSaoLei::GetButtonGroundMarkNum(int row, int cloum)
{
	int num = 0;
	if (GetOneButtonState(row - 1, cloum - 1) == mark)
		num++;
	if (GetOneButtonState(row - 1, cloum) == mark)
		num++;
	if (GetOneButtonState(row - 1, cloum + 1) == mark)
		num++;
	if (GetOneButtonState(row, cloum - 1) == mark)
		num++;
	if (GetOneButtonState(row, cloum + 1) == mark)
		num++;
	if (GetOneButtonState(row + 1, cloum - 1) == mark)
		num++;
	if (GetOneButtonState(row + 1, cloum) == mark)
		num++;
	if (GetOneButtonState(row + 1, cloum + 1) == mark)
		num++;
	return num;
}

void MSaoLei::viturlClickUnKnowButton(int X, int Y)
{
	if (X<0 || Y<0 || X>(CurrentXLength - 1) || Y>(CurrentYLength - 1))
	{
		return;
	}
	SlButton *button = (SlButton*)ui.tableWidget->cellWidget(X, Y);
	State mState = button->mState;
	buttonType type = button->GetType();
	switch (mState)
	{
	case State::clicked:
		return;
		break;
	case State::mark:
		break;
	case State::question:
		break;;
	case State::unclick:
		receiveButtonClicked(button);
		break;
	}
}

void MSaoLei::receiveButtonClicked()
{
	if (saoleiing==0)
	{
		saoleiing = 1;
		timer.start(1000);
	}
	SlButton*pushButton = dynamic_cast<SlButton*>(sender());
	State mState = pushButton->mState;
	buttonType type = pushButton->GetType();
	switch (mState)
	{
	case State::clicked:
		ui.pushButton->setStyleSheet("QPushButton{background-image:url(:/buttonType/unknow.jpg)}");
		return;
		break;
	case State::mark:
		ui.pushButton->setStyleSheet("QPushButton{background-image:url(:/buttonType/unknow.jpg)}");
		return;
		break;
	case State::unclick:
	{
		switch (type)
		{
		case mine:
		{
			pushButton->setStyleSheet("QPushButton{background-image:url(:/buttonType/mine.jpg)}");
			ui.pushButton->setStyleSheet("QPushButton{background-image:url(:/buttonType/cry.png)}");
			SetAllButtonDisable();
			timer.stop();
			BoomPlay.play();
		}
			break;
		default: //
		{
			int num = GetMineNum(pushButton->X, pushButton->Y);
			pushButton->setStyleSheet("");
			pushButton->groundMineNum = num;
			if (num)
			{
				pushButton->mType = mineground;
				pushButton->setText(QString::number(num));
				pushButton->setStyleSheet(GetStyleSheetWithNum(num));
				qDebug() << "click reason" + QString::number(pushButton->X) + " " + QString::number(pushButton->Y) + " mState  clicked mType mineground";
			}
			else {
				pushButton->mType = blank;
				emit viurlClickblanksignal(pushButton->X, pushButton->Y);
				qDebug() << "click reason" + QString::number(pushButton->X) + " " + QString::number(pushButton->Y) + " mState  clicked mType blank";
			}
			ui.pushButton->setStyleSheet("QPushButton{background-image:url(:/buttonType/unknow.jpg)}");
		}
			break;
		}
		pushButton->mState = State::clicked;
	}
	break;
	}
}

void MSaoLei::receiveButtonClicked(SlButton *pushButton)
{
	if (saoleiing == 0)
	{
		saoleiing = 1;
		timer.start(1000);
	}
	State mState = pushButton->mState;
	buttonType type = pushButton->GetType();
	switch (mState)
	{
	case State::clicked:
		ui.pushButton->setStyleSheet("QPushButton{background-image:url(:/buttonType/unknow.jpg)}");
		return;
		break;
	case State::mark:
		ui.pushButton->setStyleSheet("QPushButton{background-image:url(:/buttonType/unknow.jpg)}");
		return;
		break;
	case State::unclick:
	{
		switch (type)
		{
		case mine:
		{
			pushButton->setStyleSheet("QPushButton{background-image:url(:/buttonType/mine.jpg)}");
			ui.pushButton->setStyleSheet("QPushButton{background-image:url(:/buttonType/cry.png)}");
			SetAllButtonDisable();
			timer.stop();
			BoomPlay.play();
		}
		break;
		default: //
		{
			int num = GetMineNum(pushButton->X, pushButton->Y);
			pushButton->setStyleSheet("");
			pushButton->groundMineNum = num;
			if (num)
			{
				pushButton->mType = mineground;
				pushButton->setText(QString::number(num));
				pushButton->setStyleSheet(GetStyleSheetWithNum(num));
				qDebug() << "viturl reason" + QString::number(pushButton->X) + " " + QString::number(pushButton->Y) + " mState  clicked mType mineground";
			}
			else {
				qDebug() << "viturl reason" + QString::number(pushButton->X) + " " + QString::number(pushButton->Y) + " mState  clicked mType blank";
				pushButton->mType = blank;
				emit viurlClickblanksignal(pushButton->X, pushButton->Y);
			}
			ui.pushButton->setStyleSheet("QPushButton{background-image:url(:/buttonType/unknow.jpg)}");
		}
		break;
		}
		pushButton->mState = State::clicked;
	}
	break;
	}
}

void MSaoLei::StopGame()
{
	saoleiing = 0;
	spendtime = 0;
	timer.stop();
	ui.lcdNumber_2->display(QString::number(spendtime));
	qDeleteAll(buttonList);
	buttonList.clear();
	minebuttonList.clear();
	ui.tableWidget->setRowCount(0);
	ui.tableWidget->setColumnCount(0);
	ui.pushButton->setStyleSheet("QPushButton{background-image:url(:/buttonType/unknow.jpg)}");
}

void MSaoLei::receiveButtonRightClicked()
{
	if (saoleiing == 0)
	{
		saoleiing = 1;
		timer.start(1000);
	}
	SlButton*pushButton = dynamic_cast<SlButton*>(sender());
	State mState = pushButton->mState;
	buttonType type = pushButton->GetType();
	switch (mState)
	{
	case State::clicked:
		return;
		break;
	case State::mark:
		RestMineNum--;
		SetRestMine();
		break;
	case State::question:
		RestMineNum++;
		SetRestMine();
		break;;
	case State::unclick:
		break;
	}
}

void MSaoLei::receiveButttonRightAndLeftClicked()
{
	SlButton*pushButton = dynamic_cast<SlButton*>(sender());
	State mState = pushButton->mState;
	buttonType type = pushButton->GetType();
	switch (mState) 
	{
	case State::clicked:
	{
		int X = pushButton->X;
		int Y = pushButton->Y;
		if (pushButton->groundMineNum == GetButtonGroundMarkNum(X, Y))
		{
			viturlClickUnKnowButton(X - 1, Y - 1);
			viturlClickUnKnowButton(X - 1, Y);
			viturlClickUnKnowButton(X - 1, Y + 1);
			viturlClickUnKnowButton(X, Y - 1);
			viturlClickUnKnowButton(X, Y + 1);
			viturlClickUnKnowButton(X + 1, Y - 1);
			viturlClickUnKnowButton(X + 1, Y);
			viturlClickUnKnowButton(X + 1, Y + 1);
		}
		SetButtonGroundShow(pushButton->X, pushButton->Y, false);
	}
		break;
	case mark:
		SetButtonGroundShow(pushButton->X,pushButton->Y,false);
		break;
	case question:
		SetButtonGroundShow(pushButton->X, pushButton->Y, false);
		break;
	case unclick:
		break;	
	}
}

void MSaoLei::receiveButttonRightAndLeftRelease()
{
	SlButton*pushButton = dynamic_cast<SlButton*>(sender());
	State mState = pushButton->mState;
	buttonType type = pushButton->GetType();
	switch (mState)
	{
	case State::clicked:
		SetButtonGroundShow(pushButton->X, pushButton->Y, true);
		break;
	case mark:
		SetButtonGroundShow(pushButton->X, pushButton->Y, true);
		break;
	case question:
		SetButtonGroundShow(pushButton->X, pushButton->Y, true);
		break;
	case unclick:
		break;
	}
}

void MSaoLei::timerSlot()
{
	spendtime++;
	ui.lcdNumber_2->display(QString::number(spendtime));
}

void MSaoLei::on_pushButton_clicked()
{
	StopGame();
	CreateSaoLeiWidget(CurrentXLength, CurrentYLength, CurrentMineNum);

}

void MSaoLei::recieveButtonPress()
{
	ui.pushButton->setStyleSheet("QPushButton{background-image:url(:/buttonType/clicked.jpg)}");
}

void MSaoLei::viurlClickblankslot(int X, int Y)
{
	SetBlankButtonGround(X - 1, Y - 1);
	SetBlankButtonGround(X - 1, Y);
	SetBlankButtonGround(X - 1, Y + 1);
	SetBlankButtonGround(X , Y - 1);
	SetBlankButtonGround(X, Y +1);
	SetBlankButtonGround(X +1, Y - 1);
	SetBlankButtonGround(X +1, Y);
	SetBlankButtonGround(X +1, Y +1);
}

void MSaoLei::on_actionlow_triggered()
{
	StopGame();
	CreateSaoLeiWidget(9, 9, 10);
}

void MSaoLei::on_actionMidhight_triggered()
{
	StopGame();
	CreateSaoLeiWidget(16, 16, 40);
}

void MSaoLei::on_actionHight_triggered()
{
	StopGame();
	CreateSaoLeiWidget(16, 30, 99);
}
