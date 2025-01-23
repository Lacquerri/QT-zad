#ifndef WPIS_H
#define WPIS_H
#include <QDateTime>

enum class typ_wspomnienia {
    smutne,
    neutralne,
    radosne
};

class wpis
{
private:
    QDateTime data;
    QString tresc;
    typ_wspomnienia typ = typ_wspomnienia::neutralne;
public:
    QDateTime getData();
    QString getTresc();
    void setData(QDateTime data1);
    void setTresc(QString);
    wpis(QDateTime data1,QString tekst);
    wpis(QDateTime data1,QString tekst,typ_wspomnienia t);
    bool operator==(wpis w2);
    bool operator>(wpis& w2);
    bool operator<(wpis& w2);
    QString toQString();
    typ_wspomnienia getTyp();
};

#endif // WPIS_H
