
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
    connect(app,SIGNAL(stworzonoKopie(bool)),
            this,SLOT(on_stworzonoKopie(bool)));

    connect(app,SIGNAL(przywrocKopie(bool)),
            this,SLOT(on_przywrocKopie(bool)));
    connect(app,SIGNAL(wyswietlTypy(typ_wspomnienia, typ_wspomnienia, typ_wspomnienia)),
            this,SLOT(on_wyswietlTypy(typ_wspomnienia, typ_wspomnienia, typ_wspomnienia)));

    app->odczytDanych();
    //if(darkmode)
        //ui->radioButton->setChecked(1);
}

Pamietnik::~Pamietnik()
{
    delete ui;
}



void Pamietnik::on_stworzonoKopie(bool result)
{
    if(result)
     QMessageBox::information(this, "OK", "Zapisano kopię");
    else
     QMessageBox::warning(this, "Błąd", "Nie udało się zapisać kopii ");
}



void Pamietnik::on_przywrocKopie(bool result)
{
    if(result)
        QMessageBox::information(this, "OK", "Przywrócono kopię");
    else
        QMessageBox::warning(this, "Błąd", "Nie udało się przywrócić kopii ");

    ui->smutneBox->setChecked(1);
    ui->NeutralneBox->setChecked(1);
    ui->RadosneBox->setChecked(1);
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
    //ui->textEdit_3->setStyleSheet("border-color: red; border-style: solid; border-width: 3px;");
    ui->textEdit_3->setPlainText(w1);
    ui->textEdit_2->setPlainText(w2);
    ui->textEdit_4->setPlainText(w3);
}

void Pamietnik::on_wyswietlTypy(typ_wspomnienia w1,typ_wspomnienia w2,typ_wspomnienia w3)
{

    switch (w1) {
    default:
    case typ_wspomnienia::smutne:
        ui->textEdit_3->setStyleSheet("border-color: red; border-style: solid; border-width: 3px;");
        break;

    case typ_wspomnienia::neutralne:
        ui->textEdit_3->setStyleSheet("border-color: yellow; border-style: solid; border-width: 3px;");
        break;

    case typ_wspomnienia::radosne:
        ui->textEdit_3->setStyleSheet("border-color: green; border-style: solid; border-width: 3px;");
        break;
    }


    switch (w2) {
    default:
    case typ_wspomnienia::smutne:
        ui->textEdit_2->setStyleSheet("border-color: red; border-style: solid; border-width: 3px;");
        break;

    case typ_wspomnienia::neutralne:
        ui->textEdit_2->setStyleSheet("border-color: yellow; border-style: solid; border-width: 3px;");
        break;

    case typ_wspomnienia::radosne:
        ui->textEdit_2->setStyleSheet("border-color: green; border-style: solid; border-width: 3px;");
        break;
    }

    switch (w3) {
    default:
    case typ_wspomnienia::smutne:
        ui->textEdit_4->setStyleSheet("border-color: red; border-style: solid; border-width: 3px;");
        break;

    case typ_wspomnienia::neutralne:
        ui->textEdit_4->setStyleSheet("border-color: yellow; border-style: solid; border-width: 3px;");
        break;

    case typ_wspomnienia::radosne:
        ui->textEdit_4->setStyleSheet("border-color: green; border-style: solid; border-width: 3px;");
        break;
    }
}


void Pamietnik::on_dodajButton_clicked()
{
    mainApp->dodajWindow();
    ui->smutneBox->setChecked(1);
    ui->NeutralneBox->setChecked(1);
    ui->RadosneBox->setChecked(1);
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

void Pamietnik::on_button_PrzywrocKopie_clicked()
{
    mainApp->przywrocKopieZapas();
}


void Pamietnik::on_button_StworzKopie_clicked()
{
    mainApp->stworzKopie();
}


void Pamietnik::on_filtrButton_clicked()
{
    bool s =ui->smutneBox->isChecked();
    bool n =ui->NeutralneBox->isChecked();
    bool r =ui->RadosneBox->isChecked();
    if(s && n && r)
    {
        ui->usunButton->setEnabled(true);
    }
    else
    {
        ui->usunButton->setEnabled(false);
    }
    mainApp->filtruj(s, n, r);
}



void Pamietnik::wykonajTesty(QDebug &diag)
{
    if(this->testFiltrowania(diag))
        diag << "PASSED.\n";
    else
        diag << "FAILED!\n";
}



bool Pamietnik::testFiltrowania(QDebug &diag)
{
    ui->NeutralneBox->setChecked(false);
    mainApp->wczytajBazeTestowa();
    this->on_filtrButton_clicked();
    QString OczekiwaneWspomnienie1 = "Brak wspomnienia";
    QString OczekiwaneWspomnienie2 = "Thu Jan 1 00:00:00 1920\nWspomnienie radosne 3";
    QString OczekiwaneWspomnienie3 = "Wed Jan 1 00:00:00 1919\nWspomnienie radosne 2";

    QString FaktyczneWspomnienie1 = ui->textEdit_3->toPlainText();
    QString FaktyczneWspomnienie2 = ui->textEdit_2->toPlainText();
    QString FaktyczneWspomnienie3 = ui->textEdit_4->toPlainText();

    if(OczekiwaneWspomnienie1==FaktyczneWspomnienie1 && OczekiwaneWspomnienie2==FaktyczneWspomnienie2 && OczekiwaneWspomnienie3==FaktyczneWspomnienie3)
    return true;
    else
    return false;

}
