#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QDate data = QDate::currentDate();
    ui->dateEdit->setDate(data);
    ui->statusbar->showMessage(ui->radioButton->text());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_doubleSpinBox_valueChanged(double arg1)
{
    double kwadrat = arg1*arg1;
    QString tekst = QString::number(kwadrat, 'f', 4);
    ui->label->setText(tekst);
}


void MainWindow::on_pushButton_clicked()
{
    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(true);
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->pushButton_2->setEnabled(false);
    ui->pushButton->setEnabled(true);
}


void MainWindow::on_dateEdit_userDateChanged(const QDate &date)
{
    ui->calendarWidget->setSelectedDate(date);

}


void MainWindow::on_calendarWidget_activated(const QDate &date)
{
    ui->dateEdit->setDate(date);
}


void MainWindow::on_radioButton_toggled(bool checked)
{
    if(checked){
        ui->statusbar->showMessage(ui->radioButton->text());
    }
}


void MainWindow::on_radioButton_2_toggled(bool checked)
{
    if(checked){
        ui->statusbar->showMessage(ui->radioButton_2->text());
    }
}


void MainWindow::on_radioButton_3_toggled(bool checked)
{
    if(checked){
        ui->statusbar->showMessage(ui->radioButton_3->text());
    }
}


void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    ui->spinBox->setValue(value);
}


void MainWindow::on_horizontalSlider_2_valueChanged(int value)
{
    ui->spinBox_2->setValue(value);
}


void MainWindow::on_horizontalSlider_3_valueChanged(int value)
{
    ui->spinBox_3->setValue(value);
}


void MainWindow::on_spinBox_valueChanged(int arg1)
{
    ui->horizontalSlider->setValue(arg1);
    mieszanie();
}


void MainWindow::on_spinBox_2_valueChanged(int arg1)
{
    ui->horizontalSlider_2->setValue(arg1);
    mieszanie();
}


void MainWindow::on_spinBox_3_valueChanged(int arg1)
{
    ui->horizontalSlider_3->setValue(arg1);
    mieszanie();
}

void MainWindow::mieszanie(){
    int r, g, b;
    QPixmap piksmap(211,61);
    r=ui->spinBox->value();
    g=ui->spinBox_2->value();
    b=ui->spinBox_3->value();
    QColor kolorek =QColor::fromRgb(r,g,b);
    piksmap.fill(kolorek);
     ui->label_2->setPixmap(piksmap);
}
