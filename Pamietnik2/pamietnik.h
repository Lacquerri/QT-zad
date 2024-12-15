#ifndef PAMIETNIK_H
#define PAMIETNIK_H

#include <QWidget>
#include <qdatetime.h>
#include <deque>

QT_BEGIN_NAMESPACE
namespace Ui {
class Pamietnik;
}
QT_END_NAMESPACE

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
};

class Pamietnik : public QWidget
{
    Q_OBJECT

public:
    Pamietnik(QWidget *parent = nullptr);
    ~Pamietnik();
    void aktualizuj();

private slots:
    void on_dodajButton_clicked();

    void on_nextButton_clicked();

    void on_prevButton_clicked();

private:
    Ui::Pamietnik *ui;
    std::deque<wpis> listaWpisow;
    int str =0;
};


#endif // PAMIETNIK_H
