#ifndef PAMIETNIK_BACKEND_H
#define PAMIETNIK_BACKEND_H
#include <deque>
#include <QFile>
#include "wpis.h"


class Pamietnik_backend
{
private:
    std::deque<wpis> listaWpisow;
    int str =0;
    bool darkmode = 0;

public:
    Pamietnik_backend();
    void aktualizuj();
    void ladujplik();
    void set_darkmode(bool arg);
    void dodajWpis(QString text, QDateTime data1);
    void nastepnyIndex();
    void poprzedniIndex();
    bool zapisDoPliku();
    void usunWpis();
    void set_str(int strona);
    int get_str();
    bool getDarkmode();
    std::deque<wpis>* getListaWpisow();
    QString getWpisQString( int index );
};

#endif // PAMIETNIK_BACKEND_H
