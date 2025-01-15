#include "wpis.h"

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

QString wpis::toQString()
{
    QString data = this->getData().toString();
    QString tresc = this->getTresc();
    QString wynik = data + "\n" + tresc;
    return wynik;
}
