#include "obrazki.h"
#include "ui_obrazki.h"
#include <QMouseEvent>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>

obrazki::obrazki(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::obrazki)
{
    ui->setupUi(this);

    zdjecie z1("fajna ryba","C:/Users/i9/Desktop/ryba1.jpg");
    zdjecie z2("niezla ryba","C:/Users/i9/Desktop/ryba2.jpg");
    zdjecie z3("no ta to jest fajna","C:/Users/i9/Desktop/ryba3.jpg");
    zdjecie z4("no cos tam","C:/Users/i9/Desktop/ryba4.jpg");
    zdjecie z5("ryba fajna","C:/Users/i9/Desktop/ryba5.jpg");
    listaZdjec.push_back(z1);
    listaZdjec.push_back(z2);
    listaZdjec.push_back(z3);
    listaZdjec.push_back(z4);
    listaZdjec.push_back(z5);
    QPixmap pixm(z1.sciezka);
    ui->labelObraz->setPixmap(pixm);
    ui->labelKom->setText(z1.komentarz);
    timer1->setTimerType(Qt::VeryCoarseTimer);
    ui->lineEditSciezka->setReadOnly(true);
    ui->lineEditKom->setReadOnly(true);
}

obrazki::~obrazki()
{
    delete ui;
}


void obrazki::slotTimer(){
    if(i<listaZdjec.size()){
        QPixmap pixm(listaZdjec[i].sciezka);
        ui->labelObraz->setPixmap(pixm);
        ui->labelKom->setText(listaZdjec[i].komentarz);
        i++;
    }
    else {
        timer1->stop();
        i = 0;
    }
}

void obrazki::on_pushButton_2_clicked()
{
    timer1->setInterval(ui->spinBox->value()*1000);
    connect(timer1, SIGNAL(timeout()), this, SLOT(slotTimer()));
    timer1->start();
}


void obrazki::on_pushButton_3_clicked()
{
    timer1->stop();
    i = 0;
    QPixmap pixm(listaZdjec[0].sciezka);
    ui->labelObraz->setPixmap(pixm);
    ui->labelKom->setText(listaZdjec[0].komentarz);
}


void obrazki::on_pushButton_clicked()
{
    QString sciez = ui->lineEditSciezka->text();
    QString kom = ui->lineEditKom->text();
    zdjecie zdj(kom,sciez);
    listaZdjec.push_back(zdj);
    ui->lineEditSciezka->setText("");
    ui->lineEditKom->setText("");
    ui->lineEditKom->setReadOnly(true);
}

void obrazki::mousePressEvent(QMouseEvent *event){
    pressx_pos = event->pos().x();
    pressy_pos = event->pos().y();
}

void obrazki::mouseReleaseEvent(QMouseEvent *event){
    releasex_pos = event->pos().x();
    releasey_pos = event->pos().y();
    QPixmap pixm;

    //prawo-lewo
    if( abs(pressx_pos - releasex_pos) > abs(pressy_pos - releasey_pos))
    {
        if(pressx_pos > releasex_pos){
            //lewo
            if(i<listaZdjec.size()-1){
            i++;
            pixm=QPixmap(listaZdjec[i].sciezka);
            ui->labelObraz->setPixmap(pixm);
            ui->labelKom->setText(listaZdjec[i].komentarz);
            }
        }
        else if (pressx_pos < releasex_pos){
            //prawo
            if(i>0){
                i--;
                pixm=QPixmap(listaZdjec[i].sciezka);
                ui->labelObraz->setPixmap(pixm);
                ui->labelKom->setText(listaZdjec[i].komentarz);
            }
        }
    }
    //gora-dol
    else if(abs(pressx_pos - releasex_pos) < abs(pressy_pos - releasey_pos)){
        if(pressy_pos > releasey_pos){
            //gora
            QString fileName = QFileDialog::getOpenFileName(this, "Open the file");
            if (fileName.isEmpty())
                return;
            ui->lineEditSciezka->setText(fileName);
            ui->lineEditKom->setReadOnly(false);
        }
        else if (pressy_pos < releasey_pos){
            //dol
            if(i<listaZdjec.size()-1){
                listaZdjec.erase(listaZdjec.begin()+i);
                pixm=QPixmap(listaZdjec[i].sciezka);
                ui->labelObraz->setPixmap(pixm);
                ui->labelKom->setText(listaZdjec[i].komentarz);
            }
            else{
                QCoreApplication::quit();
            }
        }
    }
}

