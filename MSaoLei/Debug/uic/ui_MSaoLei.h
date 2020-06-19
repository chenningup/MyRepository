/********************************************************************************
** Form generated from reading UI file 'MSaoLei.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MSAOLEI_H
#define UI_MSAOLEI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MSaoLeiClass
{
public:
    QAction *actionlow;
    QAction *actionMidhight;
    QAction *actionHight;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLCDNumber *lcdNumber;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;
    QLCDNumber *lcdNumber_2;
    QTableWidget *tableWidget;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MSaoLeiClass)
    {
        if (MSaoLeiClass->objectName().isEmpty())
            MSaoLeiClass->setObjectName(QString::fromUtf8("MSaoLeiClass"));
        MSaoLeiClass->resize(380, 462);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MSaoLeiClass->sizePolicy().hasHeightForWidth());
        MSaoLeiClass->setSizePolicy(sizePolicy);
        actionlow = new QAction(MSaoLeiClass);
        actionlow->setObjectName(QString::fromUtf8("actionlow"));
        actionMidhight = new QAction(MSaoLeiClass);
        actionMidhight->setObjectName(QString::fromUtf8("actionMidhight"));
        actionHight = new QAction(MSaoLeiClass);
        actionHight->setObjectName(QString::fromUtf8("actionHight"));
        centralWidget = new QWidget(MSaoLeiClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lcdNumber = new QLCDNumber(centralWidget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        lcdNumber->setFont(font);

        horizontalLayout->addWidget(lcdNumber);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(35, 35));
        pushButton->setMaximumSize(QSize(35, 35));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(14);
        font1.setBold(false);
        font1.setWeight(50);
        pushButton->setFont(font1);

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        lcdNumber_2 = new QLCDNumber(centralWidget);
        lcdNumber_2->setObjectName(QString::fromUtf8("lcdNumber_2"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setPointSize(20);
        lcdNumber_2->setFont(font2);
        lcdNumber_2->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout->addWidget(lcdNumber_2);


        verticalLayout->addLayout(horizontalLayout);

        tableWidget = new QTableWidget(centralWidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setRowCount(0);
        tableWidget->horizontalHeader()->setVisible(false);
        tableWidget->horizontalHeader()->setMinimumSectionSize(35);
        tableWidget->horizontalHeader()->setDefaultSectionSize(35);
        tableWidget->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setMinimumSectionSize(35);
        tableWidget->verticalHeader()->setDefaultSectionSize(35);
        tableWidget->verticalHeader()->setHighlightSections(true);

        verticalLayout->addWidget(tableWidget);

        MSaoLeiClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MSaoLeiClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 380, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MSaoLeiClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MSaoLeiClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MSaoLeiClass->addToolBar(Qt::TopToolBarArea, mainToolBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(actionlow);
        menu->addAction(actionMidhight);
        menu->addAction(actionHight);

        retranslateUi(MSaoLeiClass);

        QMetaObject::connectSlotsByName(MSaoLeiClass);
    } // setupUi

    void retranslateUi(QMainWindow *MSaoLeiClass)
    {
        MSaoLeiClass->setWindowTitle(QCoreApplication::translate("MSaoLeiClass", "MSaoLei", nullptr));
        actionlow->setText(QCoreApplication::translate("MSaoLeiClass", "\344\275\216\351\232\276\345\272\246", nullptr));
        actionMidhight->setText(QCoreApplication::translate("MSaoLeiClass", "\344\270\255\347\255\211\351\232\276\345\272\246", nullptr));
        actionHight->setText(QCoreApplication::translate("MSaoLeiClass", "\351\253\230\351\232\276\345\272\246", nullptr));
        pushButton->setText(QString());
        menu->setTitle(QCoreApplication::translate("MSaoLeiClass", "\346\270\270\346\210\217\351\232\276\345\272\246", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MSaoLeiClass: public Ui_MSaoLeiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MSAOLEI_H
