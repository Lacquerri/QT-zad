#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::Dialog(bool dm, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    darkmode = dm;
    if(darkmode)
    {
        this->setStyleSheet("background-color:rgb(25,25,25); color:white;");
        ui->buttonBox->setStyleSheet("color:white;background-color:rgb(15,15,15);");
        ui->textEdit->setStyleSheet("background-color:rgb(15,15,15);");
    }
}

Dialog::~Dialog()
{
    delete ui;
}

QString Dialog::getText() const
{
    QString text = ui->textEdit->toPlainText();
    return text;

}

QDateTime Dialog::getDate() const
{
    QDateTime data1 = ui->dateTimeEdit->dateTime();
    return data1;
}

