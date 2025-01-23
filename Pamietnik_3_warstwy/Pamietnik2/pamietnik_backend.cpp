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
                out<<(int)(listaWpisow[i].getTyp());
                out<<"\n";
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




bool Pamietnik_backend::zapisKopia()
{
    QString fileName = "wpisy_backup.txt";
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
                out<<(int)(listaWpisow[i].getTyp());
                out<<"\n";
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



bool Pamietnik_backend::przywrocKopia()
{
    QFile file("wpisy_backup.txt");

    if (!file.open(QIODevice::ReadOnly | QFile::Text))
    {
        return false;
    }

    if(file.size()!=0)
    {
        listaWpisow.clear();
        QTextStream wpisy(&file);
        QString dataString;
        QDateTime dataczas;
        QString text;
        QString line;
        QString typWspomnienia_string;
        int typWspomnienia_int;
        typ_wspomnienia typWsp;
        darkmode = wpisy.readLine().toInt();
        str=wpisy.readLine().toInt();
        while(true)
        {
            typWspomnienia_string = wpisy.readLine();
            typWspomnienia_int = typWspomnienia_string.toInt();
            typWsp = (typ_wspomnienia)typWspomnienia_int;
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
            wpis w(dataczas, text, typWsp);
            listaWpisow.push_back(w);
            text="";
            if(wpisy.atEnd()) break;
        }
        listaFiltered=listaWpisow;
        str_filtered=str;
    }
    return true;
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
        QString typWspomnienia_string;
        int typWspomnienia_int;
        typ_wspomnienia typWsp;
        darkmode = wpisy.readLine().toInt();
        str=wpisy.readLine().toInt();
        while(true)
        {
            typWspomnienia_string = wpisy.readLine();
            typWspomnienia_int = typWspomnienia_string.toInt();
            typWsp = (typ_wspomnienia)typWspomnienia_int;
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
            wpis w(dataczas, text, typWsp);
            listaWpisow.push_back(w);
            text="";
            if(wpisy.atEnd()) break;
        }
        listaFiltered=listaWpisow;
        str_filtered=str;
    }

}



void Pamietnik_backend::usunWpis()
{
    listaWpisow.erase((listaWpisow.begin()+str));
    str=0;
    aktualizuj();
    listaFiltered=listaWpisow;
    str_filtered=str;
}



std::deque<wpis>* Pamietnik_backend::getListaWpisow()
{
    return &listaWpisow;
}



std::deque<wpis>* Pamietnik_backend::getListaFiltered()
{
    return &listaFiltered;
}



void Pamietnik_backend::set_str(int strona)
{
    str = strona;
}



int Pamietnik_backend::get_str()
{
    return str;
}


void Pamietnik_backend::set_str_filtered(int strona)
{
    str_filtered = strona;
}



int Pamietnik_backend::get_str_filtered()
{
    return str_filtered;
}


QString Pamietnik_backend::getWpisQString(int index)
{
    if(index >= 0 && index < (listaWpisow.size()))
        return listaWpisow[index].toQString();

    else
        return "Brak wspomnienia";
}



QString Pamietnik_backend::getWpisQString_filtered(int index)
{
    if(index >= 0 && index < (listaFiltered.size()))
        return listaFiltered[index].toQString();

    else
        return "Brak wspomnienia";
}



typ_wspomnienia Pamietnik_backend::getWpisTyp( int index )
{
    if(index >= 0 && index < (listaWpisow.size()))
        return listaWpisow[index].getTyp();

    else
        return typ_wspomnienia::neutralne;
}



typ_wspomnienia Pamietnik_backend::getWpisTyp_filtered( int index )
{
    if(index >= 0 && index < (listaFiltered.size()))
        return listaFiltered[index].getTyp();

    else
        return typ_wspomnienia::neutralne;
}



void Pamietnik_backend::set_darkmode(bool arg)
{
    darkmode = arg;
}


bool Pamietnik_backend::getDarkmode()
{
    return darkmode;
}



void Pamietnik_backend::updateFiltered()
{
    listaFiltered=listaWpisow;
}


void Pamietnik_backend::BazaTestowa()
{
    QDateTime data1 = QDateTime::fromString("12", "yy");
    QDateTime data2 = QDateTime::fromString("13", "yy");
    QDateTime data3 = QDateTime::fromString("14", "yy");

    QDateTime data4 = QDateTime::fromString("15", "yy");
    QDateTime data5 = QDateTime::fromString("16", "yy");
    QDateTime data6 = QDateTime::fromString("17", "yy");

    QDateTime data7 = QDateTime::fromString("18", "yy");
    QDateTime data8 = QDateTime::fromString("19", "yy");
    QDateTime data9 = QDateTime::fromString("20", "yy");


    QString tresc1 = "Wspomnienie smutne 1";
    QString tresc2 = "Wspomnienie smutne 2";
    QString tresc3 = "Wspomnienie smutne 3";

    QString tresc4 = "Wspomnienie neutralne 1";
    QString tresc5 = "Wspomnienie neutralne 2";
    QString tresc6 = "Wspomnienie neutralne 3";

    QString tresc7 = "Wspomnienie radosne 1";
    QString tresc8 = "Wspomnienie radosne 2";
    QString tresc9 = "Wspomnienie radosne 3";

    wpis w1(data1,tresc1,typ_wspomnienia::smutne);
    wpis w2(data2,tresc2,typ_wspomnienia::smutne);
    wpis w3(data3,tresc3,typ_wspomnienia::smutne);

    wpis w4(data4,tresc4,typ_wspomnienia::neutralne);
    wpis w5(data5,tresc5,typ_wspomnienia::neutralne);
    wpis w6(data6,tresc6,typ_wspomnienia::neutralne);

    wpis w7(data7,tresc7,typ_wspomnienia::radosne);
    wpis w8(data8,tresc8,typ_wspomnienia::radosne);
    wpis w9(data9,tresc9,typ_wspomnienia::radosne);

    listaWpisow.clear();

    listaWpisow.push_back(w1);
    listaWpisow.push_back(w2);
    listaWpisow.push_back(w3);
    listaWpisow.push_back(w4);
    listaWpisow.push_back(w5);
    listaWpisow.push_back(w6);
    listaWpisow.push_back(w7);
    listaWpisow.push_back(w8);
    listaWpisow.push_back(w9);
    aktualizuj();
    listaFiltered = listaWpisow;
}


bool Pamietnik_backend::zapisDoBazy() {

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("baza.db");

    if (!db.open()) {
        return false;
    }

    QString tresc;
    QDateTime data;
    int typWpis;

    for (int i = 0; i < listaWpisow.size(); ++i) {

        tresc = listaWpisow[i].getTresc();
        data = listaWpisow[i].getData();
        typWpis = (int)(listaWpisow[i].getTyp());
        QSqlQuery query;
        query.prepare("INSERT INTO tabela (tresc, data, typ) VALUES (:tresc, :data, :typ)");
        query.bindValue(":tresc", tresc);
        query.bindValue(":data", data);
        query.bindValue(":typ", typWpis);
        if (!query.exec()) {
            return false;
        }
    }


    db.close();
    return true;
}



bool Pamietnik_backend::odczytZBazy() {

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("baza.db");

    if (!db.open()) {
        return false;
    }

    QString tresc;
    QDateTime data;
    typ_wspomnienia typWpis;

    QSqlQuery query;
    query.prepare("SELECT COUNT * FROM tabela");
    int limit = query.value(0).toInt();

    for (int i = 1; i <= limit; ++i) {
        query.prepare("SELECT tresc, data, typ FROM tabela WHERE id = :id");
        query.bindValue(":id", i);
        if (!query.exec()) {
            return false;
        }
        tresc = query.value(0).toString();
        data = query.value(1).toDateTime();
        typWpis = (typ_wspomnienia)(query.value(2).toInt());
        wpis w(data,tresc,typWpis);
        listaWpisow.push_back(w);
    }

    aktualizuj();
    db.close();
    return true;
}
