#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    void subtractions_arror();
    void mult_error();
    void solve_error();
    ~Dialog();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
