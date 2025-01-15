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
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Pamietnik
{
public:
    QVBoxLayout *verticalLayout;
    QSplitter *splitter_3;
    QLabel *label;
    QSplitter *splitter;
    QTextEdit *textEdit_3;
    QTextEdit *textEdit_2;
    QTextEdit *textEdit_4;
    QRadioButton *radioButton;
    QSplitter *splitter_2;
    QPushButton *dodajButton;
    QPushButton *usunButton;
    QPushButton *nextButton;
    QPushButton *prevButton;

    void setupUi(QWidget *Pamietnik)
    {
        if (Pamietnik->objectName().isEmpty())
            Pamietnik->setObjectName(QString::fromUtf8("Pamietnik"));
        Pamietnik->resize(752, 531);
        Pamietnik->setMinimumSize(QSize(0, 0));
        Pamietnik->setMouseTracking(false);
        Pamietnik->setTabletTracking(false);
        verticalLayout = new QVBoxLayout(Pamietnik);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        splitter_3 = new QSplitter(Pamietnik);
        splitter_3->setObjectName(QString::fromUtf8("splitter_3"));
        splitter_3->setOrientation(Qt::Vertical);
        label = new QLabel(splitter_3);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        splitter_3->addWidget(label);
        splitter = new QSplitter(splitter_3);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        textEdit_3 = new QTextEdit(splitter);
        textEdit_3->setObjectName(QString::fromUtf8("textEdit_3"));
        splitter->addWidget(textEdit_3);
        textEdit_2 = new QTextEdit(splitter);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        splitter->addWidget(textEdit_2);
        textEdit_4 = new QTextEdit(splitter);
        textEdit_4->setObjectName(QString::fromUtf8("textEdit_4"));
        splitter->addWidget(textEdit_4);
        splitter_3->addWidget(splitter);
        radioButton = new QRadioButton(splitter_3);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        splitter_3->addWidget(radioButton);

        verticalLayout->addWidget(splitter_3);

        splitter_2 = new QSplitter(Pamietnik);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        dodajButton = new QPushButton(splitter_2);
        dodajButton->setObjectName(QString::fromUtf8("dodajButton"));
        splitter_2->addWidget(dodajButton);
        usunButton = new QPushButton(splitter_2);
        usunButton->setObjectName(QString::fromUtf8("usunButton"));
        QFont font1;
        font1.setBold(true);
        usunButton->setFont(font1);
        splitter_2->addWidget(usunButton);
        nextButton = new QPushButton(splitter_2);
        nextButton->setObjectName(QString::fromUtf8("nextButton"));
        splitter_2->addWidget(nextButton);
        prevButton = new QPushButton(splitter_2);
        prevButton->setObjectName(QString::fromUtf8("prevButton"));
        splitter_2->addWidget(prevButton);

        verticalLayout->addWidget(splitter_2);


        retranslateUi(Pamietnik);

        QMetaObject::connectSlotsByName(Pamietnik);
    } // setupUi

    void retranslateUi(QWidget *Pamietnik)
    {
        Pamietnik->setWindowTitle(QCoreApplication::translate("Pamietnik", "Pamietnik", nullptr));
        label->setText(QCoreApplication::translate("Pamietnik", "Lista wpis\303\263w", nullptr));
        radioButton->setText(QCoreApplication::translate("Pamietnik", "Dark mode", nullptr));
        dodajButton->setText(QCoreApplication::translate("Pamietnik", "Dodaj wpis", nullptr));
        usunButton->setText(QCoreApplication::translate("Pamietnik", "Usu\305\204", nullptr));
        nextButton->setText(QCoreApplication::translate("Pamietnik", "Nast\304\231pny", nullptr));
        prevButton->setText(QCoreApplication::translate("Pamietnik", "Poprzedni", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Pamietnik: public Ui_Pamietnik {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAMIETNIK_H
