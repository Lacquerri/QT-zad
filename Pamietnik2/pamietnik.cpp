
#include "pamietnik.h"
#include "./ui_pamietnik.h"
#include "qevent.h"

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
    ladujplik();
    aktualizuj();
    if(darkmode)
        ui->radioButton->setChecked(1);
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
    m_okienko = new Dialog(darkmode, nullptr);

    int result = m_okienko->exec();

    if(result){
        QString text = m_okienko->getText();
        QDateTime data1 = m_okienko->getDate();
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

        delete m_okienko;
    }

/*
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
*/
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

void Pamietnik::closeEvent(QCloseEvent *event){
    QString fileName = "wpisy.txt";
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        event->ignore();
    }
    else{
    QTextStream out(&file);
        if(listaWpisow.size()==0){
        out<<"";
        }
        else{
            out<<darkmode;
            out<<"\n";
            out<<str;
            out<<"\n";
            for(int i=0;i<listaWpisow.size();i++){
                out << listaWpisow[i].getData().toString(Qt::ISODate);
                out << "\n";
                out << listaWpisow[i].getTresc();
                out << "\n";
                out << "$$$";
                out << "\n";
            }
            file.close();
            event->accept();
        }
    }
}

void Pamietnik::ladujplik(){
    QFile file("wpisy.txt");

    if (!file.open(QIODevice::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
        return;
    }

    if(file.size()!=0)
    {
        QTextStream wpisy(&file);
        QString dataString;
        QDateTime dataczas;
        QString text;
        QString line;
        darkmode = wpisy.readLine().toInt();
        str=wpisy.readLine().toInt();
        while(true)
        {
            dataString = wpisy.readLine();
            dataczas=QDateTime::fromString(dataString, Qt::ISODate);
            while(true)
            {
                line = wpisy.readLine();
                if (!line.contains("$$$")) {
                    text+=line;
                    text+="\n";
                }
                else {
                    text.remove((text.size()-1), 1);
                    break;
                }
            }
            wpis w(dataczas, text);
            listaWpisow.push_back(w);
            text="";
            if(wpisy.atEnd()) break;
        }
    }
}


void Pamietnik::on_usunButton_clicked()
{
    if(str >= 0 && str < listaWpisow.size())
    {
        listaWpisow.erase((listaWpisow.begin()+str));
        str=0;
        aktualizuj();
    }
}

void Pamietnik::keyPressEvent(QKeyEvent *event){
    int kod = event->key();
    switch(kod)
    {
    case (int)Qt::Key_Up:
        on_prevButton_clicked();
        break;

    case (int)Qt::Key_Down:
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
    darkmode = 1;
}

void Pamietnik::on_radioButton_toggled(bool checked)
{
    if(checked)
    {
        darkmode_ON();
    }
    else
    {
        this->setStyleSheet("background-color:white; color:black;");
        ui->usunButton->setStyleSheet("color:black;");
        ui->dodajButton->setStyleSheet("color:black;background-color:white;");
        ui->nextButton->setStyleSheet("background-color:white;");
        ui->prevButton->setStyleSheet("background-color:white;");
        ui->textEdit_2->setStyleSheet("background-color:white;");
        ui->textEdit_3->setStyleSheet("background-color:white;");
        ui->textEdit_4->setStyleSheet("background-color:white;");
        darkmode = 0;
    }
}

