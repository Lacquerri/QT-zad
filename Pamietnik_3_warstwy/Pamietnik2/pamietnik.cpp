
#include "pamietnik.h"
#include "./ui_pamietnik.h"
#include "qevent.h"
#include "program.h"

Pamietnik::Pamietnik(QWidget *parent, Program *app)
    : QWidget(parent), ui(new Ui::Pamietnik), mainApp(app)
{
    app->setGUI(this);
    ui->setupUi(this);
    ui->textEdit_2->setReadOnly(true);
    ui->textEdit_3->setReadOnly(true);
    ui->textEdit_4->setReadOnly(true);


    connect(app,SIGNAL(odswiezOkna(QString, QString, QString)),
     this,SLOT(on_odswiezOkna(QString,QString,QString)));
    connect(app,SIGNAL(signalDarkmode(bool)),
            this,SLOT(on_signalDarkmode(bool)));

    app->odczytDanych();
    //if(darkmode)
        //ui->radioButton->setChecked(1);
}

Pamietnik::~Pamietnik()
{
    delete ui;
}



void Pamietnik::on_signalDarkmode(bool checked)
{
    if(checked)
    {
        darkmode_ON();
    }
    else
    {
        darkmode_OFF();
    }
}



void Pamietnik::on_odswiezOkna(QString w1,QString w2,QString w3)
{
    ui->textEdit_3->setPlainText(w1);
    ui->textEdit_2->setPlainText(w2);
    ui->textEdit_4->setPlainText(w3);
}


void Pamietnik::on_dodajButton_clicked()
{
    mainApp->dodajWindow();
}



void Pamietnik::on_nextButton_clicked()
{
    mainApp->nextPage();
}


void Pamietnik::on_prevButton_clicked()
{
    mainApp->prevPage();
}

void Pamietnik::closeEvent(QCloseEvent *event){
    bool result = mainApp->zamknij();
    if(!result)
        event->ignore();
    else
        event->accept();
}


void Pamietnik::on_usunButton_clicked()
{
    mainApp->usun();
}

void Pamietnik::keyPressEvent(QKeyEvent *event){
    int kod = event->key();
    switch(kod)
    {
    case (int)Qt::Key_Left:
        on_prevButton_clicked();
        break;

    case (int)Qt::Key_Right:
        on_nextButton_clicked();
        break;
    }
}

void Pamietnik::darkmode_ON()
{
    this->setStyleSheet("background-color:rgb(25,25,25); color:white;");
    ui->usunButton->setStyleSheet("color:red;background-color:rgb(15,15,15);");
    ui->dodajButton->setStyleSheet("color:green;background-color:rgb(15,15,15);");
    ui->nextButton->setStyleSheet("background-color:rgb(15,15,15);");
    ui->prevButton->setStyleSheet("background-color:rgb(15,15,15);");
    ui->textEdit_2->setStyleSheet("background-color:rgb(15,15,15);");
    ui->textEdit_3->setStyleSheet("background-color:rgb(15,15,15);");
    ui->textEdit_4->setStyleSheet("background-color:rgb(15,15,15);");
    ui->radioButton->setChecked(true);
}

void Pamietnik::darkmode_OFF()
{
    this->setStyleSheet("background-color:white; color:black;");
    ui->usunButton->setStyleSheet("color:black;");
    ui->dodajButton->setStyleSheet("color:black;background-color:white;");
    ui->nextButton->setStyleSheet("background-color:white;");
    ui->prevButton->setStyleSheet("background-color:white;");
    ui->textEdit_2->setStyleSheet("background-color:white;");
    ui->textEdit_3->setStyleSheet("background-color:white;");
    ui->textEdit_4->setStyleSheet("background-color:white;");
    ui->radioButton->setChecked(false);
}

void Pamietnik::on_radioButton_toggled(bool checked)
{
    mainApp->checkButtonDarkmode(checked);
}
