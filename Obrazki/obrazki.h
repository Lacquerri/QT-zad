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

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void mousePressEvent(QMouseEvent *event) override;

    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    Ui::obrazki *ui;
    std::deque<zdjecie> listaZdjec;
    QTimer *timer1 = new QTimer(this);
    int pressx_pos;
    int pressy_pos;
    int releasex_pos;
    int releasey_pos;
};
#endif // OBRAZKI_H
