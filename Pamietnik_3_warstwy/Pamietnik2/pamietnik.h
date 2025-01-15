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


class Program;

QT_BEGIN_NAMESPACE
namespace Ui {
class Pamietnik;
}
QT_END_NAMESPACE


class Pamietnik : public QWidget
{
    Q_OBJECT

public:
    Pamietnik(QWidget *parent = nullptr,
              Program *app = nullptr);
    ~Pamietnik();
    void darkmode_ON();
    void darkmode_OFF();


private slots:
    void on_dodajButton_clicked();

    void on_nextButton_clicked();

    void on_prevButton_clicked();

    void closeEvent(QCloseEvent *event) override;

    void on_usunButton_clicked();

    void on_radioButton_toggled(bool checked);

    void on_odswiezOkna(QString w1,QString w2,QString w3);

    void on_signalDarkmode(bool checked);

private:
    Ui::Pamietnik *ui;
    Program *mainApp = nullptr;
    void keyPressEvent(QKeyEvent *event) override;
};


#endif // PAMIETNIK_H
