#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "matrix.h"
#include "dialog.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(800, 600);
    this->setStyleSheet("background-color: rgb(210, 243, 212);");
    ui->tableWidget->setStyleSheet("border: 2px solid green;");
    ui->tableWidget->verticalHeader()->hide();
    ui->tableWidget->horizontalHeader()->hide();
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
double** MainWindow::read_table(){//зчитати матрицю із таблиці 1
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
        return m1;
}
void MainWindow::on_pushButton_clicked()//обчислити визначник
{
    int row = ui->lineEdit->text().toInt();
    int col = ui->lineEdit_2->text().toInt();

      matrix new_matr(read_table(), row,col);
      int det = new_matr.det();

      bool is_empty = false;
      for(int i =0; i < row; i++){
          for(int j =0; j < col; j++){
              QTableWidgetItem *item = ui->tableWidget->item(i,j);
              if (item == NULL) {
                  is_empty = true;
                  break;
               }
          }
      }
      if(is_empty == true || row !=col){
          Dialog window;
          window.setModal(true);
          window.exec();
          ui->lineEdit_3->setText("Error");
      }
      else{
          ui->lineEdit_3->setText(QString::number(det));
      }
}


