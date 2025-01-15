/********************************************************************************
** Form generated from reading UI file 'obrazki.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OBRAZKI_H
#define UI_OBRAZKI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_obrazki
{
public:
    QWidget *centralwidget;
    QLabel *labelObraz;
    QLabel *labelKom;
    QLineEdit *lineEditKom;
    QLineEdit *lineEditSciezka;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QSpinBox *spinBox;
    QPushButton *pushButton_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *obrazki)
    {
        if (obrazki->objectName().isEmpty())
            obrazki->setObjectName("obrazki");
        obrazki->resize(933, 671);
        centralwidget = new QWidget(obrazki);
        centralwidget->setObjectName("centralwidget");
        labelObraz = new QLabel(centralwidget);
        labelObraz->setObjectName("labelObraz");
        labelObraz->setGeometry(QRect(60, 30, 811, 381));
        labelObraz->setAlignment(Qt::AlignCenter);
        labelKom = new QLabel(centralwidget);
        labelKom->setObjectName("labelKom");
        labelKom->setGeometry(QRect(10, 420, 911, 31));
        QFont font;
        font.setPointSize(18);
        labelKom->setFont(font);
        labelKom->setAlignment(Qt::AlignCenter);
        lineEditKom = new QLineEdit(centralwidget);
        lineEditKom->setObjectName("lineEditKom");
        lineEditKom->setGeometry(QRect(360, 550, 211, 24));
        lineEditSciezka = new QLineEdit(centralwidget);
        lineEditSciezka->setObjectName("lineEditSciezka");
        lineEditSciezka->setGeometry(QRect(360, 510, 211, 24));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(410, 480, 111, 20));
        label_3->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(280, 510, 71, 21));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(280, 550, 71, 21));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(420, 590, 80, 24));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(790, 420, 80, 24));
        spinBox = new QSpinBox(centralwidget);
        spinBox->setObjectName("spinBox");
        spinBox->setGeometry(QRect(740, 420, 42, 25));
        spinBox->setValue(3);
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(790, 450, 81, 24));
        obrazki->setCentralWidget(centralwidget);
        menubar = new QMenuBar(obrazki);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 933, 22));
        obrazki->setMenuBar(menubar);
        statusbar = new QStatusBar(obrazki);
        statusbar->setObjectName("statusbar");
        obrazki->setStatusBar(statusbar);

        retranslateUi(obrazki);

        QMetaObject::connectSlotsByName(obrazki);
    } // setupUi

    void retranslateUi(QMainWindow *obrazki)
    {
        obrazki->setWindowTitle(QCoreApplication::translate("obrazki", "obrazki", nullptr));
        labelObraz->setText(QString());
        labelKom->setText(QCoreApplication::translate("obrazki", "Komentarz", nullptr));
        label_3->setText(QCoreApplication::translate("obrazki", "Dodaj nowy obraz", nullptr));
        label_4->setText(QCoreApplication::translate("obrazki", "\305\232cie\305\274ka:", nullptr));
        label_5->setText(QCoreApplication::translate("obrazki", "Komentarz:", nullptr));
        pushButton->setText(QCoreApplication::translate("obrazki", "Dodaj", nullptr));
        pushButton_2->setText(QCoreApplication::translate("obrazki", "Pokaz", nullptr));
        pushButton_3->setText(QCoreApplication::translate("obrazki", "Reset", nullptr));
    } // retranslateUi

};

namespace Ui {
    class obrazki: public Ui_obrazki {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OBRAZKI_H
