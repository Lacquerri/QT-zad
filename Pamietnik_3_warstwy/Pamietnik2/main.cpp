#include "pamietnik.h"
#include "program.h"

#include <QApplication>

#define DIAG 0

#if(DIAG == 0)
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Program mainProg;
    Pamietnik w(nullptr,&mainProg);
    w.setFocus();
    w.show();


    return a.exec();
}
#endif

#if(DIAG == 1)
int main(int argc, char *argv[])
 {
 QDebug diag(QtDebugMsg);
 diag.nospace();
 diag.noquote();
 diag << "Rozpoczecie testow:\n===================================\n";
 QApplication a(argc, argv);
 Program mainProg;
 Pamietnik w(nullptr,&mainProg);
 w.wykonajTesty(diag);
 diag << "Zakonczenie testow\n";
 return 0;
 }
 #endif
