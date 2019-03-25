/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget = NULL;
    QVBoxLayout *verticalLayout = NULL;
    QGroupBox *groupBox_2 = NULL;
    QCheckBox *checkBox_2 = NULL;
    QCheckBox *checkBox_3 = NULL;
    QCheckBox *checkBox = NULL;
    QLabel *label = NULL;
    QListWidget *FileList = NULL;
    QPushButton *AddFile = NULL;
    QPushButton *pushButton = NULL;
    QStatusBar *statusbar = NULL;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 612);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        checkBox_2 = new QCheckBox(groupBox_2);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setGeometry(QRect(360, 0, 121, 25));
        checkBox_3 = new QCheckBox(groupBox_2);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));
        checkBox_3->setGeometry(QRect(560, 0, 151, 25));
        checkBox = new QCheckBox(groupBox_2);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(140, 0, 151, 25));

        verticalLayout->addWidget(groupBox_2);

        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        FileList = new QListWidget(centralwidget);
        FileList->setObjectName(QStringLiteral("FileList"));

        verticalLayout->addWidget(FileList);

        AddFile = new QPushButton(centralwidget);
        AddFile->setObjectName(QStringLiteral("AddFile"));

        verticalLayout->addWidget(AddFile);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(AddFile, SIGNAL(clicked()), MainWindow, SLOT(AddFile()));
        QObject::connect(pushButton, SIGNAL(clicked()), MainWindow, SLOT(sendFile()));
        QObject::connect(pushButton, SIGNAL(clicked()), FileList, SLOT(clear()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "TYPE", 0));
        checkBox_2->setText(QApplication::translate("MainWindow", "IP ADDRESS", 0));
        checkBox_3->setText(QApplication::translate("MainWindow", "EMAIL ADDRESS", 0));
        checkBox->setText(QApplication::translate("MainWindow", "PHONE NUMBER", 0));
        label->setText(QApplication::translate("MainWindow", "All files selected :", 0));
        AddFile->setText(QApplication::translate("MainWindow", "Find a file", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Send file", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
