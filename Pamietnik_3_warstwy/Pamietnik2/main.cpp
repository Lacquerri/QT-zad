#include "pamietnik.h"
#include "program.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Program mainProg;
    Pamietnik w(nullptr,&mainProg);
    w.setFocus();
    w.show();


    return a.exec();
}
