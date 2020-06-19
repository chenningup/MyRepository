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
	void CreateSaoLeiWidget(int XLength,int Ylength, int MineNum);//����ɨ�׽���
	void WidgetResize(int XLength,int Ylength);
	QList<int> CreateMineList(int num,int X,int Y);//������ɶ��ٸ��׵����
	void SetMineButton(int index);//����ĳ��buttonΪ��
	int GetMineNum(int row, int cloum);//��ȡĳ��button�ܱ��м�����
	buttonType GetOneButtonType(int row,int cloum);//��ȡĳ��button������
	State GetOneButtonState(int row,int cloum);
	void SetAllButtonDisable();//��������button��Ч
	QTimer timer;//��ʱ
	QMediaPlayer BoomPlay;//��������
	void SetRestMine();//����ʣ���������
	QString GetStyleSheetWithNum(int num);//�����ܱ��׵����� ������ɫ
	void SetBlankButtonGround(int X,int Y); //���¿հ׼��� ���ܱߵ�button����Ϊclicked;
	void SetButtonGroundShow(int X, int Y, bool isnormal);//������Ҽ�ͬʱ����  button�ܱߵ���ʾ�仯
	void SetOneButtonShow(int X, int Y, bool isnormal);//����һ��button�ı仯
	int GetButtonGroundMarkNum(int row,int cloum);
	void viturlClickUnKnowButton(int X, int Y);
	void receiveButtonClicked(SlButton *pushButton);
	void StopGame();
signals:
	void viurlClickblanksignal(int X,int Y);//����İ���ĳ������  ��SetBlankButtonGround����ʹ��
public slots:
	void receiveButtonClicked();//�յ�button�������
	void receiveButtonRightClicked();//�յ�button�Ҽ�����
	void receiveButttonRightAndLeftClicked();//�յ�button���Ҽ�ͬʱ����
	void receiveButttonRightAndLeftRelease();//�յ�button���Ҽ�ͬʱ�ͷ�
	void timerSlot();
	void on_pushButton_clicked();
	void recieveButtonPress();//�յ�button���»�û���ͷ�
	void viurlClickblankslot(int X,int Y);//����viurlClickblanksignalʹ�� ����İ���blankButton�ܱ����еļ�
	void on_actionlow_triggered();
	void on_actionMidhight_triggered();
	void on_actionHight_triggered();
private:
    Ui::MSaoLeiClass ui;
};
