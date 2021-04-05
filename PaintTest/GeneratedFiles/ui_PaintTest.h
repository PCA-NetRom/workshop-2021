/********************************************************************************
** Form generated from reading UI file 'PaintTest.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAINTTEST_H
#define UI_PAINTTEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PaintTest
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *action;
    QAction *actionExit;
    QAction *actionNew;
    QWidget *centralWidget;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *PaintTest)
    {
        if (PaintTest->objectName().isEmpty())
            PaintTest->setObjectName(QString::fromUtf8("PaintTest"));
        PaintTest->resize(600, 400);
        actionOpen = new QAction(PaintTest);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionSave = new QAction(PaintTest);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        action = new QAction(PaintTest);
        action->setObjectName(QString::fromUtf8("action"));
        actionExit = new QAction(PaintTest);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionNew = new QAction(PaintTest);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        centralWidget = new QWidget(PaintTest);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        PaintTest->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(PaintTest);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 26));
        PaintTest->setMenuBar(menuBar);

        retranslateUi(PaintTest);

        QMetaObject::connectSlotsByName(PaintTest);
    } // setupUi

    void retranslateUi(QMainWindow *PaintTest)
    {
        PaintTest->setWindowTitle(QCoreApplication::translate("PaintTest", "PaintTest", nullptr));
        actionOpen->setText(QCoreApplication::translate("PaintTest", "Open...", nullptr));
        actionSave->setText(QCoreApplication::translate("PaintTest", "Save..", nullptr));
        action->setText(QCoreApplication::translate("PaintTest", "-", nullptr));
        actionExit->setText(QCoreApplication::translate("PaintTest", "Exit", nullptr));
        actionNew->setText(QCoreApplication::translate("PaintTest", "New", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PaintTest: public Ui_PaintTest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAINTTEST_H
