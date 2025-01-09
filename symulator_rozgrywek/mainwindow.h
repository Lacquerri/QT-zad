#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QListWidget>
#include<QListWidgetItem>
#include <QMainWindow>
#include <mylabel.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void zmiana_etapu(QString prev, QString next);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
