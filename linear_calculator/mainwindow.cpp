#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "matrix.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(800, 600);
    this->setStyleSheet("background-color: rgb(210, 243, 212);");
    ui->tableWidget->setStyleSheet("border: none;");

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::create_cell(){

     int row = ui->lineEdit->text().toInt();
     int col = ui->lineEdit_2->text().toInt();
     ui->tableWidget->setRowCount(row);
     ui->tableWidget->setColumnCount(col);
     ui->tableWidget->horizontalHeader()->setDefaultSectionSize(20);
     ui->tableWidget->verticalHeader()->setDefaultSectionSize(20);

}

void MainWindow::on_lineEdit_editingFinished()
{
    create_cell();
}


void MainWindow::on_lineEdit_2_editingFinished()
{
    create_cell();
}

void MainWindow::on_pushButton_clicked()
{

    int row = ui->lineEdit->text().toInt();
    int col = ui->lineEdit_2->text().toInt();
        double** m1 = new double* [row];
        for (int i = 0; i < row; i++) {
         m1[i] = new double[col];
        }
        for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++){
                    QString check;
                    QTableWidgetItem *item = ui->tableWidget->item(i,j);
                    if (NULL != item) {
                        check = item->text();
                     }
                 m1[i][j] = check.toInt();
                }
       }
      matrix new_matr(m1, row,col);
      int det = new_matr.det();
      ui->lineEdit_3->setText(QString::number(det));
}


