#ifndef DIALOG_H
#define DIALOG_H

#include "wpis.h"
#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    Dialog(bool dm, QWidget *parent = nullptr);
    ~Dialog();
    QString getText() const;
    QDateTime getDate() const;
    typ_wspomnienia getType();

private:
    Ui::Dialog *ui;
    bool darkmode = 0;
};

#endif // DIALOG_H
