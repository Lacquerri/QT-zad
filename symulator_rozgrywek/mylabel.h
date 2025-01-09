#ifndef MYLABEL_H
#define MYLABEL_H
#include <QLabel>
#include <QStringList>

class Mylabel: public QLabel
{

    Q_OBJECT

public:
    Mylabel(QWidget *parent = nullptr);


    void nextString();
    void prevString();

private:
    QStringList lista;
    int curr_index = 0;

public slots:
    void setLista(QStringList nowalista);

signals:
    void zmien(QString poprzedni, QString nastepny);

};

#endif // MYLABEL_H
