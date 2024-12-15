#include "pamietnik.h"
#include "./ui_pamietnik.h"

QDateTime wpis::getData(){return data;}
QString wpis::getTresc(){return tresc;}
void wpis::setData(QDateTime data1){data=data1;}
void wpis::setTresc(QString tekst){tresc=tekst;}
wpis::wpis(QDateTime data1,QString tekst)
{
    setData(data1);
    setTresc(tekst);
}

bool wpis::operator==(wpis w2)
{
    QDateTime d1 =this->getData();
    QDateTime d2 =w2.data;
    if(d1!=d2) return false;
    else return true;
}

bool wpis::operator>(wpis& w2)
{
    QDateTime d1 =this->getData();
    QDateTime d2 =w2.getData();
    return (d1>d2);
}

bool wpis::operator<(wpis& w2)
{
    QDateTime d1 =this->getData();
    QDateTime d2 =w2.getData();
    return (d1<d2);
}

Pamietnik::Pamietnik(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Pamietnik)
{
    ui->setupUi(this);
    ui->textEdit_2->setReadOnly(true);
    ui->textEdit_3->setReadOnly(true);
    ui->textEdit_4->setReadOnly(true);
    aktualizuj();
}

Pamietnik::~Pamietnik()
{
    delete ui;
}

bool cmp(wpis w1, wpis w2){
    return w2<w1;
}

void Pamietnik::aktualizuj()
{
    ui->textEdit_2->setPlainText("");
    ui->textEdit_3->setPlainText("");
    ui->textEdit_4->setPlainText("");
    std::sort(listaWpisow.begin(),listaWpisow.end(),&cmp);
    QString strdata;
    QString tekst;
    if(listaWpisow.size()==0){
        ui->textEdit_2->setFontItalic(true);
        ui->textEdit_2->setPlainText("Brak wspomnienia");
    }
    else{
    ui->textEdit_2->setFontItalic(false);
    strdata = listaWpisow[str].getData().toString();
    tekst = listaWpisow[str].getTresc();
    ui->textEdit_2->insertPlainText(strdata);
    ui->textEdit_2->insertPlainText("\n");
    ui->textEdit_2->insertPlainText(tekst);
    }

    if(str-1<0){
        ui->textEdit_3->setFontItalic(true);
        ui->textEdit_3->setPlainText("Brak wspomnienia");
    }
    else{
         ui->textEdit_3->setFontItalic(false);
        strdata = listaWpisow[str-1].getData().toString();
        tekst = listaWpisow[str-1].getTresc();
        ui->textEdit_3->insertPlainText(strdata);
        ui->textEdit_3->insertPlainText("\n");
        ui->textEdit_3->insertPlainText(tekst);
    }

    if(str+1>=listaWpisow.size()){
        ui->textEdit_4->setFontItalic(true);
        ui->textEdit_4->setPlainText("Brak wspomnienia");
    }
    else{
        ui->textEdit_4->setFontItalic(false);
        strdata = listaWpisow[str+1].getData().toString();
        tekst = listaWpisow[str+1].getTresc();
        ui->textEdit_4->insertPlainText(strdata);
        ui->textEdit_4->insertPlainText("\n");
        ui->textEdit_4->insertPlainText(tekst);
    }

}

void Pamietnik::on_dodajButton_clicked()
{
    QString text = ui->textEdit->toPlainText();
    QDateTime data1 = ui->dateTimeEdit->dateTime();
    wpis w(data1,text);

    if(std::count(listaWpisow.begin(), listaWpisow.end(), w)>0){
        auto it = std::find(listaWpisow.begin(), listaWpisow.end(), w);
        int index = std::distance(listaWpisow.begin(),it);
        listaWpisow[index]=w;
    }

    else{
        this->listaWpisow.push_back(w);
    }

    aktualizuj();
    ui->textEdit->setPlainText("");
}



void Pamietnik::on_nextButton_clicked()
{
    if(str+1<listaWpisow.size()){
        str++;
        aktualizuj();
    }
}


void Pamietnik::on_prevButton_clicked()
{
    if(str-1>=0){
        str--;
        aktualizuj();
    }
}

