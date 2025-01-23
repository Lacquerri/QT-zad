#ifndef PAMIETNIK_BACKEND_H
#define PAMIETNIK_BACKEND_H
#include <deque>
#include <QFile>
#include <QtSql>
#include "wpis.h"


class Pamietnik_backend
{
private:
    std::deque<wpis> listaWpisow;
    std::deque<wpis> listaFiltered;
    int str =0;
    int str_filtered =0;
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
    bool zapisKopia();
    bool przywrocKopia();
    void usunWpis();
    void set_str(int strona);
    int get_str();
    bool getDarkmode();
    std::deque<wpis>* getListaWpisow();
    std::deque<wpis>* getListaFiltered();
    QString getWpisQString( int index );
    QString getWpisQString_filtered( int index );
    typ_wspomnienia getWpisTyp( int index );
    typ_wspomnienia getWpisTyp_filtered( int index );
    void set_str_filtered(int strona);
    int get_str_filtered();
    void updateFiltered();
    void BazaTestowa();
    bool zapisDoBazy();
    bool odczytZBazy();
};

#endif // PAMIETNIK_BACKEND_H
