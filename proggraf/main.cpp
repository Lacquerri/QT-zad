#include "program_graf.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    program_graf w;
    w.show();
    return a.exec();
}
