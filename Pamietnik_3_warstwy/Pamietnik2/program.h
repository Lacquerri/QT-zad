#ifndef PROGRAM_H
#define PROGRAM_H

#include <QObject>
#include "pamietnik_backend.h"
#include "dialog.h"

class Pamietnik;


class Program : public QObject
{
    Q_OBJECT
public:
    explicit Program(QObject *parent = nullptr){}
    void setGUI(Pamietnik *ui = nullptr) {GUI = ui;}
    void dodajWindow();
    bool zamknij();
    void odczytDanych();
    void nextPage();
    void prevPage();
    void usun();
    void checkButtonDarkmode(bool checked);
    void stworzKopie();
    void przywrocKopieZapas();
    void filtruj(bool s, bool n, bool r);
    void wczytajBazeTestowa();


private:
    Pamietnik *GUI= nullptr;
    Dialog *m_okienko;
    Pamietnik_backend m_pamietnik;

signals:
    void odswiezOkna(QString, QString, QString);
    void wyswietlTypy(typ_wspomnienia, typ_wspomnienia, typ_wspomnienia);
    void signalDarkmode(bool);
    void stworzonoKopie(bool);
    void przywrocKopie(bool);
};

#endif // PROGRAM_H
