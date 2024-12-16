#ifndef OBRAZKI_H
#define OBRAZKI_H

#include <QMainWindow>
#include <deque>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class obrazki; }
QT_END_NAMESPACE


struct zdjecie{
    QString komentarz;
    QString sciezka;
    zdjecie(QString kom, QString path)
    {
        komentarz=kom;
        sciezka=path;
    }
};


class obrazki : public QMainWindow
{
    Q_OBJECT

public:
    obrazki(QWidget *parent = nullptr);
    ~obrazki();
    int i = 0;

private slots:
    void on_pushButton_2_clicked();
    void slotTimer();

private:
    Ui::obrazki *ui;
    std::deque<zdjecie> listaZdjec;
    QTimer *timer1 = new QTimer(this);

};
#endif // OBRAZKI_H
