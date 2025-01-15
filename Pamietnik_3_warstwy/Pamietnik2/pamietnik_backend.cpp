#include "pamietnik_backend.h"

Pamietnik_backend::Pamietnik_backend() {}

bool cmp(wpis w1, wpis w2){
    return w2<w1;
}



void Pamietnik_backend::aktualizuj()
{
    std::sort(listaWpisow.begin(),listaWpisow.end(),&cmp);
}



void Pamietnik_backend::dodajWpis(QString text, QDateTime data1)
{
    wpis w(data1,text);

    if(std::count(listaWpisow.begin(), listaWpisow.end(), w)>0)
    {
        auto it = std::find(listaWpisow.begin(), listaWpisow.end(), w);
        int index = std::distance(listaWpisow.begin(),it);
        listaWpisow[index]=w;
    }

    else
    {
        this->listaWpisow.push_back(w);
    }

    aktualizuj();
}



void Pamietnik_backend::nastepnyIndex()
{
    str++;
}



void Pamietnik_backend::poprzedniIndex()
{
    str--;
}



bool Pamietnik_backend::zapisDoPliku()
{
    QString fileName = "wpisy.txt";
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        return false;
    }
    else
    {
        QTextStream out(&file);
        if(listaWpisow.size()==0)
        {
            out<<"";
        }
        else
        {
            out<<darkmode;
            out<<"\n";
            out<<str;
            out<<"\n";
            for(int i=0;i<listaWpisow.size();i++)
            {
                out << listaWpisow[i].getData().toString(Qt::ISODate);
                out << "\n";
                out << listaWpisow[i].getTresc();
                out << "\n";
                out << "$$$";
                out << "\n";
            }
        }
        file.close();
        return true;
    }
}



void Pamietnik_backend::ladujplik()
{
    QFile file("wpisy.txt");

    if (!file.open(QIODevice::ReadOnly | QFile::Text))
    {
        return;
    }

    if(file.size()!=0)
    {
        QTextStream wpisy(&file);
        QString dataString;
        QDateTime dataczas;
        QString text;
        QString line;
        darkmode = wpisy.readLine().toInt();
        str=wpisy.readLine().toInt();
        while(true)
        {
            dataString = wpisy.readLine();
            dataczas=QDateTime::fromString(dataString, Qt::ISODate);
            while(true)
            {
                line = wpisy.readLine();
                if (!line.contains("$$$")) {
                    text+=line;
                    text+="\n";
                }
                else {
                    text.remove((text.size()-1), 1);
                    break;
                }
            }
            wpis w(dataczas, text);
            listaWpisow.push_back(w);
            text="";
            if(wpisy.atEnd()) break;
        }
    }
}



void Pamietnik_backend::usunWpis()
{
    listaWpisow.erase((listaWpisow.begin()+str));
    str=0;
    aktualizuj();
}



std::deque<wpis>* Pamietnik_backend::getListaWpisow()
{
    return &listaWpisow;
}



void Pamietnik_backend::set_str(int strona)
{
    str = strona;
}



int Pamietnik_backend::get_str()
{
    return str;
}



QString Pamietnik_backend::getWpisQString(int index)
{
    if(index >= 0 && index < (listaWpisow.size()))
        return listaWpisow[index].toQString();

    else
        return "Brak wspomnienia";
}



void Pamietnik_backend::set_darkmode(bool arg)
{
    darkmode = arg;
}


bool Pamietnik_backend::getDarkmode()
{
    return darkmode;
}
