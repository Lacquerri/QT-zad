/********************************************************************************
** Form generated from reading UI file 'pamietnik.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAMIETNIK_H
#define UI_PAMIETNIK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Pamietnik
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QTextEdit *textEdit_2;
    QDateTimeEdit *dateTimeEdit;
    QPushButton *dodajButton;
    QLabel *label;
    QTextEdit *textEdit;
    QTextEdit *textEdit_3;
    QTextEdit *textEdit_4;
    QPushButton *nextButton;
    QPushButton *prevButton;
    QPushButton *usunButton;

    void setupUi(QWidget *Pamietnik)
    {
        if (Pamietnik->objectName().isEmpty())
            Pamietnik->setObjectName(QString::fromUtf8("Pamietnik"));
        Pamietnik->resize(752, 600);
        Pamietnik->setMinimumSize(QSize(752, 600));
        Pamietnik->setMaximumSize(QSize(752, 600));
        Pamietnik->setMouseTracking(false);
        Pamietnik->setTabletTracking(false);
        scrollArea = new QScrollArea(Pamietnik);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(10, 40, 311, 521));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setEnabled(true);
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 309, 519));
        scrollArea->setWidget(scrollAreaWidgetContents);
        scrollArea_2 = new QScrollArea(Pamietnik);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setGeometry(QRect(340, 190, 401, 231));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 399, 229));
        textEdit_2 = new QTextEdit(scrollAreaWidgetContents_2);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setGeometry(QRect(0, 0, 401, 231));
        scrollArea_2->setWidget(scrollAreaWidgetContents_2);
        dateTimeEdit = new QDateTimeEdit(Pamietnik);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        dateTimeEdit->setGeometry(QRect(10, 10, 194, 22));
        dodajButton = new QPushButton(Pamietnik);
        dodajButton->setObjectName(QString::fromUtf8("dodajButton"));
        dodajButton->setGeometry(QRect(250, 10, 75, 24));
        label = new QLabel(Pamietnik);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(460, 10, 151, 20));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        textEdit = new QTextEdit(Pamietnik);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 40, 311, 521));
        textEdit_3 = new QTextEdit(Pamietnik);
        textEdit_3->setObjectName(QString::fromUtf8("textEdit_3"));
        textEdit_3->setGeometry(QRect(340, 40, 401, 141));
        textEdit_4 = new QTextEdit(Pamietnik);
        textEdit_4->setObjectName(QString::fromUtf8("textEdit_4"));
        textEdit_4->setGeometry(QRect(340, 430, 401, 131));
        nextButton = new QPushButton(Pamietnik);
        nextButton->setObjectName(QString::fromUtf8("nextButton"));
        nextButton->setGeometry(QRect(670, 570, 75, 24));
        prevButton = new QPushButton(Pamietnik);
        prevButton->setObjectName(QString::fromUtf8("prevButton"));
        prevButton->setGeometry(QRect(590, 570, 75, 24));
        usunButton = new QPushButton(Pamietnik);
        usunButton->setObjectName(QString::fromUtf8("usunButton"));
        usunButton->setGeometry(QRect(340, 570, 75, 24));
        QFont font1;
        font1.setBold(true);
        usunButton->setFont(font1);

        retranslateUi(Pamietnik);

        QMetaObject::connectSlotsByName(Pamietnik);
    } // setupUi

    void retranslateUi(QWidget *Pamietnik)
    {
        Pamietnik->setWindowTitle(QCoreApplication::translate("Pamietnik", "Pamietnik", nullptr));
        dodajButton->setText(QCoreApplication::translate("Pamietnik", "Dodaj wpis", nullptr));
        label->setText(QCoreApplication::translate("Pamietnik", "Poprzednie wpisy", nullptr));
        nextButton->setText(QCoreApplication::translate("Pamietnik", "Nast\304\231pny", nullptr));
        prevButton->setText(QCoreApplication::translate("Pamietnik", "Poprzedni", nullptr));
        usunButton->setText(QCoreApplication::translate("Pamietnik", "Usu\305\204", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Pamietnik: public Ui_Pamietnik {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAMIETNIK_H
