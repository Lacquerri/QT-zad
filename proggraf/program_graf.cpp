#include "program_graf.h"
#include "ui_program_graf.h"

program_graf::program_graf(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::program_graf)
{
    ui->setupUi(this);
}

program_graf::~program_graf()
{
    delete ui;
}
