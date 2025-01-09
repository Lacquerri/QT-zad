#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <random>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->listWidget->addItem("Pawlik");
    ui->listWidget->addItem("Adamczyk");
    ui->listWidget->addItem("Jędrzejowski");
        ui->listWidget->addItem("Kowalski");
    ui->listWidget->addItem("Stolarski");
    ui->listWidget->addItem("Ziółkowski");
                            QStringList lista = (QStringList() << "Ćwierć-finał" << "Pół-finał" << "Finał");
        ui->label->setLista(lista);

    connect(ui->label,SIGNAL(zmien(QString,QString)), this, SLOT(zmiana_etapu(QString,QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::zmiana_etapu(QString prev, QString next)
{
    QString text = prev + "->" + next;
    ui->statusbar->showMessage(text);
}

void MainWindow::on_pushButton_clicked()
{
    ui->label->prevString();
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->label->nextString();
}

void MainWindow::on_pushButton_3_clicked()
{
    std::random_device gen_los;
    std::mt19937 gen_plos;
    gen_plos.seed(gen_los());
    std::uniform_int_distribution<int> uniDistInt(1, 2);
    if(uniDistInt(gen_plos)==1){
        ui->lineEdit->setStyleSheet("background-color: green;");
        ui->lineEdit_2->setStyleSheet("background-color: red;");
        QMessageBox::information(this, "Winner", ui->lineEdit->text());
    }
    else if(uniDistInt(gen_plos)==2){
        ui->lineEdit_2->setStyleSheet("background-color: green;");
        ui->lineEdit->setStyleSheet("background-color: red;");
        QMessageBox::information(this, "Winner", ui->lineEdit_2->text());
    }

}

void MainWindow::on_pushButton_4_clicked()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();

    ui->pushButton_3->setEnabled(0);

    ui->lineEdit_2->setStyleSheet("background-color: white;");
    ui->lineEdit->setStyleSheet("background-color: white;");
    ui->statusbar->showMessage("");
}





void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    if(ui->lineEdit->text().isEmpty())
        ui->lineEdit->setText(item->text());

    else if(ui->lineEdit_2->text().isEmpty())
    {
        ui->lineEdit_2->setText(item->text());
        ui->pushButton_3->setEnabled(1);
    }
}

