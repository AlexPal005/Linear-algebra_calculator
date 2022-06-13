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
    ui->tableWidget_2->setStyleSheet("border: 2px solid green;");
    ui->tableWidget_2->verticalHeader()->hide();
    ui->tableWidget_2->horizontalHeader()->hide();
    ui->tableWidget_3->setStyleSheet("border: 2px solid green;");
    ui->tableWidget_3->verticalHeader()->hide();
    ui->tableWidget_3->horizontalHeader()->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::get_row_A(){
      return ui->lineEdit->text().toInt();
}
int MainWindow::get_row_B(){
      return ui->lineEdit_4->text().toInt();
}
int MainWindow::get_col_A(){
      return ui->lineEdit_2->text().toInt();
}
int MainWindow::get_col_B(){
      return ui->lineEdit_5->text().toInt();
}
void MainWindow::create_cell(int row, int col){
     ui->tableWidget->setRowCount(row);
     ui->tableWidget->setColumnCount(col);
     ui->tableWidget->horizontalHeader()->setDefaultSectionSize(20);
     ui->tableWidget->verticalHeader()->setDefaultSectionSize(20);

}
void MainWindow::create_cell_B(int row, int col){
     ui->tableWidget_2->setRowCount(row);
     ui->tableWidget_2->setColumnCount(col);
     ui->tableWidget_2->horizontalHeader()->setDefaultSectionSize(20);
     ui->tableWidget_2->verticalHeader()->setDefaultSectionSize(20);

}

void MainWindow::on_lineEdit_editingFinished()
{
    create_cell(get_row_A(), get_col_A());
}


void MainWindow::on_lineEdit_2_editingFinished()
{
    create_cell(get_row_A(), get_col_A());
}
double** MainWindow::read_table(){//зчитати матрицю із таблиці 1
    int row = get_row_A();
    int col = get_col_A();
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
double** MainWindow::read_table_B(){//зчитати матрицю із таблиці 1
    int row = get_row_B();
    int col = get_col_B();
        double** m1 = new double* [row];
        for (int i = 0; i < row; i++) {
         m1[i] = new double[col];
        }
        for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++){
                    QString check;
                    QTableWidgetItem *item = ui->tableWidget_2->item(i,j);
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
    int row = get_row_A();
    int col = get_col_A();

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


void MainWindow::on_lineEdit_4_editingFinished()
{
    create_cell_B(get_row_B(), get_col_B());
}


void MainWindow::on_lineEdit_5_editingFinished()
{
   create_cell_B(get_row_B(), get_col_B());
}


void MainWindow::on_pushButton_2_clicked()
{
    int row_A = get_row_A();
    int col_A = get_col_A();
    if(get_row_A()==get_row_B() && get_col_A()==get_col_B()){
        matrix new_matr_A(read_table(), get_row_A(),get_col_A());
        matrix new_matr_B(read_table_B(), get_row_B(),get_col_B());

        ui->tableWidget_3->setRowCount(row_A);
        ui->tableWidget_3->setColumnCount(col_A);
        ui->tableWidget_3->horizontalHeader()->setDefaultSectionSize(20);
        ui->tableWidget_3->verticalHeader()->setDefaultSectionSize(20);
        double** matr = new_matr_A.subtraction_matrix(new_matr_A, new_matr_B);
        for (int i = 0; i < row_A; i++) {
            for (int j = 0; j < col_A; j++){
               QTableWidgetItem *item = new QTableWidgetItem(QString:: number(matr[i][j]));
               ui->tableWidget_3->setItem(i,j,item);
            }
         }
    }
    else{
        Dialog window;
        window.subtractions_arror();
        window.setModal(true);
        window.exec();
    }

}


void MainWindow::on_pushButton_3_clicked()
{
    int row_A = get_row_A();
    int col_A = get_col_A();
    if(get_row_A()==get_row_B() && get_col_A()==get_col_B()){
        matrix new_matr_A(read_table(), get_row_A(),get_col_A());
        matrix new_matr_B(read_table_B(), get_row_B(),get_col_B());

        ui->tableWidget_3->setRowCount(row_A);
        ui->tableWidget_3->setColumnCount(col_A);
        ui->tableWidget_3->horizontalHeader()->setDefaultSectionSize(20);
        ui->tableWidget_3->verticalHeader()->setDefaultSectionSize(20);
        double** matr = new_matr_A.sum_matrix(new_matr_A, new_matr_B);
        for (int i = 0; i < row_A; i++) {
            for (int j = 0; j < col_A; j++){
               QTableWidgetItem *item = new QTableWidgetItem(QString:: number(matr[i][j]));
               ui->tableWidget_3->setItem(i,j,item);
            }
         }
    }
    else{
        Dialog window;
        window.subtractions_arror();
        window.setModal(true);
        window.exec();
    }

}

void MainWindow::on_pushButton_4_clicked()
{
    int row_A = get_row_A();
    int col_A = get_col_A();
    matrix new_matr_A(read_table(), get_row_A(),get_col_A());

    ui->tableWidget_3->setRowCount(row_A);
    ui->tableWidget_3->setColumnCount(col_A);
    ui->tableWidget_3->horizontalHeader()->setDefaultSectionSize(20);
    ui->tableWidget_3->verticalHeader()->setDefaultSectionSize(20);
    int num = ui->lineEdit_6->text().toInt();
    double** matr = new_matr_A.multiplic_number(num);
    for (int i = 0; i < row_A; i++) {
        for (int j = 0; j < col_A; j++){
           QTableWidgetItem *item = new QTableWidgetItem(QString:: number(matr[i][j]));
           ui->tableWidget_3->setItem(i,j,item);
        }
     }
}


void MainWindow::on_pushButton_5_clicked()
{
    int row_A = get_row_A();
    if(get_col_A()==get_row_B()){
        matrix new_matr_A(read_table(), get_row_A(),get_col_A());
        matrix new_matr_B(read_table_B(), get_row_B(),get_col_B());

        ui->tableWidget_3->setRowCount(row_A);
        ui->tableWidget_3->setColumnCount(get_col_B());
        ui->tableWidget_3->horizontalHeader()->setDefaultSectionSize(20);
        ui->tableWidget_3->verticalHeader()->setDefaultSectionSize(20);
        double** matr = new_matr_A.mult(new_matr_A, new_matr_B);
        for (int i = 0; i < row_A; i++) {
            for (int j = 0; j < get_col_B(); j++){
               QTableWidgetItem *item = new QTableWidgetItem(QString:: number(matr[i][j]));
               ui->tableWidget_3->setItem(i,j,item);
            }
         }
    }
    else{
        Dialog window;
        window.mult_error();
        window.setModal(true);
        window.exec();
    }
}


void MainWindow::on_pushButton_6_clicked()
{
    matrix new_matr_A(read_table(), get_row_A(),get_col_A());

    double** arr = new_matr_A.solve();
    if(arr==0){
        Dialog window;
        window.solve_error();
        window.setModal(true);
        window.exec();
    }
    else{
        ui->tableWidget_3->setRowCount(get_row_A());
        ui->tableWidget_3->setColumnCount(2);
        ui->tableWidget_3->horizontalHeader()->setDefaultSectionSize(70);
        ui->tableWidget_3->verticalHeader()->setDefaultSectionSize(20);

        for (int i = 0; i < get_row_A(); i++) {
               QTableWidgetItem *item = new QTableWidgetItem(QString:: number(arr[i][get_col_A()-1]));
               QTableWidgetItem *item_1 = new QTableWidgetItem("X"+QString:: number(i+1)+"=");
               ui->tableWidget_3->setItem(i,0,item_1);
               ui->tableWidget_3->setItem(i,1,item);
         }
    }

}


void MainWindow::on_pushButton_7_clicked()
{
    matrix new_matr_A(read_table(), get_row_A(),get_col_A());
    double** arr = new_matr_A.transpose();
    ui->tableWidget_3->setRowCount(get_col_A());
    ui->tableWidget_3->setColumnCount(get_row_A());
    ui->tableWidget_3->horizontalHeader()->setDefaultSectionSize(20);
    ui->tableWidget_3->verticalHeader()->setDefaultSectionSize(20);
    for (int i = 0; i < get_col_A(); i++) {
        for (int j = 0; j < get_row_A(); j++){
           QTableWidgetItem *item = new QTableWidgetItem(QString:: number(arr[i][j]));
           ui->tableWidget_3->setItem(i,j,item);
        }
     }
}

