#include "mylabel.h"

Mylabel::Mylabel(QWidget* parent) : QLabel(parent)
{
    this->clear();
}



void Mylabel::setLista(QStringList nowalista)
{
    lista = nowalista;
    this->setText(lista[0]);
}


void Mylabel::nextString()
{
    QString poprzedni = this->text();
    if(curr_index < lista.size() - 1)
    {
        curr_index++;
        this->setText(lista[curr_index]);
    }
    else {
        curr_index = 0;
        this->setText(lista[curr_index]);
    }
    emit zmien(poprzedni, this->text());
}


void Mylabel::prevString()
{
    QString poprzedni = this->text();
    if(curr_index>1)
    {
        curr_index--;
        this->setText(lista[curr_index]);
    }
    else {
        curr_index = lista.size() - 1;
        this->setText(lista[curr_index]);
    }
    emit zmien(poprzedni, this->text());
}
