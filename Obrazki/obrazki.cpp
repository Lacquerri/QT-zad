#include "obrazki.h"
#include "ui_obrazki.h"

obrazki::obrazki(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::obrazki)
{
    ui->setupUi(this);

    zdjecie z1("fajna ryba","C:/Users/student/Desktop/ryba1.jpg");
    zdjecie z2("niezla ryba","C:/Users/student/Desktop/ryba2.jpg");
    zdjecie z3("no ta to jest fajna","C:/Users/student/Desktop/ryba3.jpg");
    zdjecie z4("no cos tam","C:/Users/student/Desktop/ryba4.jpg");
    zdjecie z5("ryba fajna","C:/Users/student/Desktop/ryba5.jpg");
    listaZdjec.push_back(z1);
    listaZdjec.push_back(z2);
    listaZdjec.push_back(z3);
    listaZdjec.push_back(z4);
    listaZdjec.push_back(z5);
    QPixmap pixm(z1.sciezka);
    ui->labelObraz->setPixmap(pixm);
    ui->labelKom->setText(z1.komentarz);
    timer1->setTimerType(Qt::VeryCoarseTimer);
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

