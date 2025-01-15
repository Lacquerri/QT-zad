#ifndef WPIS_H
#define WPIS_H
#include <QDateTime>

class wpis
{
private:
    QDateTime data;
    QString tresc;
public:
    QDateTime getData();
    QString getTresc();
    void setData(QDateTime data1);
    void setTresc(QString);
    wpis(QDateTime data1,QString tekst);
    bool operator==(wpis w2);
    bool operator>(wpis& w2);
    bool operator<(wpis& w2);
    QString toQString();
};

#endif // WPIS_H
