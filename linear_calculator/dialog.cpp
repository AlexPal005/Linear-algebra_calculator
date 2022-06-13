#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}
void Dialog::subtractions_arror(){
    ui->label->setText("         Матриці повинні бути\n          однакового розміру!");
}
void Dialog::mult_error(){
    ui->label->setText("Кількість стовпчиків A має дорівнювати\n кількості рядків B!");
}
void Dialog::solve_error(){
     ui->label->setText("Система не має\n розв'язку!");
}
