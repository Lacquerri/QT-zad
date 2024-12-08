/********************************************************************************
** Form generated from reading UI file 'program_graf.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROGRAM_GRAF_H
#define UI_PROGRAM_GRAF_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_program_graf
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *program_graf)
    {
        if (program_graf->objectName().isEmpty())
            program_graf->setObjectName(QString::fromUtf8("program_graf"));
        program_graf->resize(800, 600);
        centralwidget = new QWidget(program_graf);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        program_graf->setCentralWidget(centralwidget);
        menubar = new QMenuBar(program_graf);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        program_graf->setMenuBar(menubar);
        statusbar = new QStatusBar(program_graf);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        program_graf->setStatusBar(statusbar);

        retranslateUi(program_graf);

        QMetaObject::connectSlotsByName(program_graf);
    } // setupUi

    void retranslateUi(QMainWindow *program_graf)
    {
        program_graf->setWindowTitle(QCoreApplication::translate("program_graf", "program_graf", nullptr));
    } // retranslateUi

};

namespace Ui {
    class program_graf: public Ui_program_graf {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROGRAM_GRAF_H
