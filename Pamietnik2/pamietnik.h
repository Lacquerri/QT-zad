#ifndef PAMIETNIK_H
#define PAMIETNIK_H

#include <QWidget>
#include <qdatetime.h>
#include <deque>
#include <QCloseEvent>
#include <QFile>
#include <QMessageBox>
#include <QDebug>
#include <QKeyEvent>
#include "dialog.h"

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
    void ladujplik();
    void darkmode_ON();


private slots:
    void on_dodajButton_clicked();

    void on_nextButton_clicked();

    void on_prevButton_clicked();

    void closeEvent(QCloseEvent *event) override;

    void on_usunButton_clicked();



    void on_radioButton_toggled(bool checked);

private:
    Ui::Pamietnik *ui;
    std::deque<wpis> listaWpisow;
    int str =0;
    void keyPressEvent(QKeyEvent *event) override;
    Dialog *m_okienko;
    bool darkmode = 0;
};


#endif // PAMIETNIK_H
