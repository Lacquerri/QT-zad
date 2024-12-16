#include "pamietnik.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Pamietnik w;
    w.setFocus();
    w.show();
    return a.exec();
}
