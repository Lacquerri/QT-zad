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

    void setupUi(QWidget *Pamietnik)
    {
        if (Pamietnik->objectName().isEmpty())
            Pamietnik->setObjectName(QString::fromUtf8("Pamietnik"));
        Pamietnik->resize(752, 590);
        Pamietnik->setMinimumSize(QSize(752, 590));
        Pamietnik->setMaximumSize(QSize(752, 590));
        scrollArea = new QScrollArea(Pamietnik);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(10, 40, 311, 521));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 309, 519));
        scrollArea->setWidget(scrollAreaWidgetContents);
        scrollArea_2 = new QScrollArea(Pamietnik);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setGeometry(QRect(340, 40, 401, 521));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 399, 519));
        textEdit_2 = new QTextEdit(scrollAreaWidgetContents_2);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setGeometry(QRect(0, 0, 401, 521));
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

        retranslateUi(Pamietnik);

        QMetaObject::connectSlotsByName(Pamietnik);
    } // setupUi

    void retranslateUi(QWidget *Pamietnik)
    {
        Pamietnik->setWindowTitle(QCoreApplication::translate("Pamietnik", "Pamietnik", nullptr));
        dodajButton->setText(QCoreApplication::translate("Pamietnik", "Dodaj wpis", nullptr));
        label->setText(QCoreApplication::translate("Pamietnik", "Poprzednie wpisy", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Pamietnik: public Ui_Pamietnik {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAMIETNIK_H
