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
// State的变化  有两个：右键的变化在buton里面转变  左键的变化在主UI里变化
//buttonype的变化 在主UI里面转变

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
	int groundMineNum;//周边雷的个数
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
	void emitRightClicked();//按下右键
	void emitbuttonPress();//按下左键 
	void emitRightAndLeftPress();//左右键同时按下信号
	void emitRightAndLeftRelease();
};

