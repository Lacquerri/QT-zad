#include "program.h"

void Program::dodajWindow()
{
    m_okienko = new Dialog(m_pamietnik.getDarkmode(), nullptr);

    int result = m_okienko->exec();

    if(result){
        QString text = m_okienko->getText();
        QDateTime data1 = m_okienko->getDate();
        wpis w(data1,text);

        if(std::count(m_pamietnik.getListaWpisow()->begin(), m_pamietnik.getListaWpisow()->end(), w)>0){
            auto it = std::find(m_pamietnik.getListaWpisow()->begin(), m_pamietnik.getListaWpisow()->end(), w);
            int index = std::distance(m_pamietnik.getListaWpisow()->begin(),it);
            m_pamietnik.getListaWpisow()->at(index)=w;
        }

        else{
            this->m_pamietnik.getListaWpisow()->push_back(w);
        }

        m_pamietnik.aktualizuj();

        delete m_okienko;

        m_pamietnik.set_str(0);
        QString wpis1 = m_pamietnik.getWpisQString(m_pamietnik.get_str()-1);
        QString wpis2 = m_pamietnik.getWpisQString(m_pamietnik.get_str());
        QString wpis3 = m_pamietnik.getWpisQString(m_pamietnik.get_str()+1);
        emit odswiezOkna(wpis1, wpis2, wpis3);
    }
}


bool Program::zamknij()
{
    bool result = m_pamietnik.zapisDoPliku();
    return result;
}



void Program::odczytDanych()
{
    m_pamietnik.ladujplik();
    emit signalDarkmode(m_pamietnik.getDarkmode());
    QString wpis1 = m_pamietnik.getWpisQString(m_pamietnik.get_str()-1);
    QString wpis2 = m_pamietnik.getWpisQString(m_pamietnik.get_str());
    QString wpis3 = m_pamietnik.getWpisQString(m_pamietnik.get_str()+1);
    emit odswiezOkna(wpis1, wpis2, wpis3);
}



void Program::nextPage()
{
    int limit = (m_pamietnik.getListaWpisow()->size() - 1);
    if(m_pamietnik.get_str() < limit)
    {
        m_pamietnik.set_str(m_pamietnik.get_str()+1);
        QString wpis1 = m_pamietnik.getWpisQString(m_pamietnik.get_str()-1);
        QString wpis2 = m_pamietnik.getWpisQString(m_pamietnik.get_str());
        QString wpis3 = m_pamietnik.getWpisQString(m_pamietnik.get_str()+1);
        emit odswiezOkna(wpis1, wpis2, wpis3);
    }
}



void Program::prevPage()
{
    if(m_pamietnik.get_str() > 0)
    {
        m_pamietnik.set_str(m_pamietnik.get_str()-1);
        QString wpis1 = m_pamietnik.getWpisQString(m_pamietnik.get_str()-1);
        QString wpis2 = m_pamietnik.getWpisQString(m_pamietnik.get_str());
        QString wpis3 = m_pamietnik.getWpisQString(m_pamietnik.get_str()+1);
        emit odswiezOkna(wpis1, wpis2, wpis3);
    }
}


void Program::usun()
{
    if(m_pamietnik.getListaWpisow()->size() > 1)
    {
        m_pamietnik.usunWpis();
        m_pamietnik.set_str(0);
        QString wpis1 = m_pamietnik.getWpisQString(m_pamietnik.get_str()-1);
        QString wpis2 = m_pamietnik.getWpisQString(m_pamietnik.get_str());
        QString wpis3 = m_pamietnik.getWpisQString(m_pamietnik.get_str()+1);
        emit odswiezOkna(wpis1, wpis2, wpis3);
    }
}


void Program::checkButtonDarkmode(bool checked)
{
    m_pamietnik.set_darkmode(checked);
    emit signalDarkmode(checked);
}

void Program::stworzKopie()
{
    bool result = m_pamietnik.zapisKopia();
    emit stworzonoKopie(result);
}


void Program::przywrocKopieZapas()
{

    bool result = m_pamietnik.przywrocKopia();
    emit przywrocKopie(result);
    emit signalDarkmode(m_pamietnik.getDarkmode());
    QString wpis1 = m_pamietnik.getWpisQString(m_pamietnik.get_str()-1);
    QString wpis2 = m_pamietnik.getWpisQString(m_pamietnik.get_str());
    QString wpis3 = m_pamietnik.getWpisQString(m_pamietnik.get_str()+1);
    emit odswiezOkna(wpis1, wpis2, wpis3);
}
