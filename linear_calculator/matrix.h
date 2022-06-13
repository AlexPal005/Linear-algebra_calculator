#ifndef MATRIX_H
#define MATRIX_H


class matrix
{
public:
    matrix(double** matrix, int row_in, int column_in); //конструктор
    ~matrix(); // деструктор
    void get_matrix();// надрукувати матрицю
    double** subtraction_matrix(matrix matrix_1, matrix matrix_2); //різниця матриць
    double** sum_matrix(matrix matrix_1, matrix matrix_2);//сума матриць
    double** multiplic_number(int num);// множення матриці на число
    double** mult(matrix matrix_1, matrix matrix_2);// множення матриці на матрицю
    double det(); // Визначник матриці <=3
    double det_for(double** z, int p);// визначник матриці >=3
    void memory();// очищення пам'яті
    double** solve();// вирішення рівнянь
    void single_matrix(); // створення одиничної матриці
    double** transpose(); // транспонована матриця

private:
    int row, column; // кількість рядків так стовпчиків матриці
    double** matr;
    double** elementary; // одинична матриця
};

#endif // MATRIX_H
