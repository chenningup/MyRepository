#pragma once
#include <QPushButton>
#include <QObject>
#include <QMouseEvent>
enum buttonType {
	unknow=0,
	mine=1,
	blank,
	mineground
};
enum State 
{
	unclick = 0,
	clicked,
	question,
	mark
};
// State�ı仯  ���������Ҽ��ı仯��buton����ת��  ����ı仯����UI��仯
//buttonype�ı仯 ����UI����ת��

class SlButton :public QPushButton
{
	Q_OBJECT
public:
	      SlButton();
		~SlButton();
	buttonType mType;
	State mState;
	int X;
	int Y;
	int LeftPressed;
	int RightPressed;
	int IsBothPressed;
	int groundMineNum;//�ܱ��׵ĸ���
	void SetPosition(int x, int y) {
		X = x;
		Y = y;
	};
	void SetType(buttonType atype) {
		mType = atype;
	};
	buttonType GetType() {
		return mType;
	};

	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	void HandleMousePress();
public slots:
	void clickedSlots();
	void pressSlots();
signals:
	void emitClickedSignals();
	void emitRightClicked();//�����Ҽ�
	void emitbuttonPress();//������� 
	void emitRightAndLeftPress();//���Ҽ�ͬʱ�����ź�
	void emitRightAndLeftRelease();
};

