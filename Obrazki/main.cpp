#include "obrazki.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    obrazki w;
    w.show();
    return a.exec();
}
