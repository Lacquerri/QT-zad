#ifndef PROGRAM_GRAF_H
#define PROGRAM_GRAF_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class program_graf;
}
QT_END_NAMESPACE

class program_graf : public QMainWindow
{
    Q_OBJECT

public:
    program_graf(QWidget *parent = nullptr);
    ~program_graf();

private:
    Ui::program_graf *ui;
};
#endif // PROGRAM_GRAF_H
