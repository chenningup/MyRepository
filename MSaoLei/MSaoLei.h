#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MSaoLei.h"
#include "SlButton.h"
#include <QTimer>
#include <QMediaPlayer>
class MSaoLei : public QMainWindow
{
    Q_OBJECT
public:
    MSaoLei(QWidget *parent = Q_NULLPTR);
	int saoleiing;
	int CurrentXLength;
	int CurrentYLength;
	int CurrentMineNum;
	int RestMineNum;
	int spendtime;
	QList<SlButton*>buttonList;
	QList<SlButton*>minebuttonList;
	void CreateSaoLeiWidget(int XLength,int Ylength, int MineNum);//创建扫雷界面
	void WidgetResize(int XLength,int Ylength);
	QList<int> CreateMineList(int num,int X,int Y);//随机生成多少个雷的序号
	void SetMineButton(int index);//设置某个button为雷
	int GetMineNum(int row, int cloum);//获取某个button周边有几个雷
	buttonType GetOneButtonType(int row,int cloum);//获取某个button的类型
	State GetOneButtonState(int row,int cloum);
	void SetAllButtonDisable();//设置所有button无效
	QTimer timer;//计时
	QMediaPlayer BoomPlay;//播放声音
	void SetRestMine();//设置剩余的雷数量
	QString GetStyleSheetWithNum(int num);//根据周边雷的数量 设置颜色
	void SetBlankButtonGround(int X,int Y); //按下空白键后 将周边的button都置为clicked;
	void SetButtonGroundShow(int X, int Y, bool isnormal);//左键和右键同时按下  button周边的显示变化
	void SetOneButtonShow(int X, int Y, bool isnormal);//设置一个button的变化
	int GetButtonGroundMarkNum(int row,int cloum);
	void viturlClickUnKnowButton(int X, int Y);
	void receiveButtonClicked(SlButton *pushButton);
	void StopGame();
signals:
	void viurlClickblanksignal(int X,int Y);//虚拟的按下某个键盘  和SetBlankButtonGround搭配使用
public slots:
	void receiveButtonClicked();//收到button左键按下
	void receiveButtonRightClicked();//收到button右键按下
	void receiveButttonRightAndLeftClicked();//收到button左右键同时按下
	void receiveButttonRightAndLeftRelease();//收到button左右键同时释放
	void timerSlot();
	void on_pushButton_clicked();
	void recieveButtonPress();//收到button按下还没有释放
	void viurlClickblankslot(int X,int Y);//搭配viurlClickblanksignal使用 虚拟的按下blankButton周边所有的键
	void on_actionlow_triggered();
	void on_actionMidhight_triggered();
	void on_actionHight_triggered();
private:
    Ui::MSaoLeiClass ui;
};
