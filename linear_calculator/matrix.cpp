#include "matrix.h"
#include <iostream>
#include <algorithm>

using namespace std;
matrix::matrix(double** matrix, int row_in, int column_in)
{

    row = row_in;
    column = column_in;

    /*cout << endl << "It is possible to introduce an extended matrix to solve the system!" << endl;

    cout << "Enter the number of rows of the matrix! " << endl;

    cin >> row;

    cout << endl << "Enter the number of columns in the matrix:" << endl;

    cin >> column;

    cout << endl << "Enter the numbers:" << endl;
   */
    matr = new double* [row];

    elementary = new double* [row];

    for (int i = 0; i < row; i++) {

        matr[i] = new double[column];

        elementary[i] = new double[row];

    }

    for (int i = 0; i < row; i++) {

        for (int j = 0; j < column; j++)

            matr[i][j] = matrix[i][j];

    }


}
void matrix::get_matrix() {

    cout << "Matrix:" << endl;

    for (int i = 0; i < row; i++) {

        for (int j = 0; j < column; j++)

            cout << matr[i][j] << " ";

        cout << endl;
    }

}
double** matrix::subtraction_matrix(matrix matrix_1, matrix matrix_2) {

   double** matr_res = new double* [row];

    for (int i = 0; i < row; i++) {

        matr_res[i] = new double[column];

    }

    if (matrix_2.row == matrix_1.row && matrix_2.column == matrix_1.column) { // перевірка на рівність рядків та стовпчиків

        for (int i = 0; i < row; i++) {

            for (int j = 0; j < column; j++)

                matr_res[i][j] = matrix_1.matr[i][j] - matrix_2.matr[i][j];

        }

        cout << "Subtraction done!" << endl;
        /*Друкуємо матрицю*/
        for (int i = 0; i < row; i++) {

            for (int j = 0; j < column; j++)

                cout << matr_res[i][j] << " ";

            cout << endl;

        }

        return matr_res;
    }
    else {
        cout << "The dimensions of the matrices must be the same!" << endl;
        return 0;
    }



}
double** matrix::sum_matrix(matrix matrix_1, matrix matrix_2) {

    double** matr_res = new double* [row];

    for (int i = 0; i < row; i++) {

        matr_res[i] = new double[column];

    }
    if (matrix_2.row == matrix_1.row && matrix_2.column == matrix_1.column) {

        for (int i = 0; i < row; i++) {

            for (int j = 0; j < column; j++)

                matr_res[i][j] = matrix_1.matr[i][j] + matrix_2.matr[i][j];

        }

        cout << "Add complete!" << endl;

        for (int i = 0; i < row; i++) {

            for (int j = 0; j < column; j++)

                cout << matr_res[i][j] << " ";

            cout << endl;

        }
        return matr_res;
    }

    else {

        cout << "The dimensions of the matrices must be the same!";
        return 0;
    }


}
double** matrix::multiplic_number(int num) {

    double** matr_res = new double* [row];

    for (int i = 0; i < row; i++) {

        matr_res[i] = new double[column];

    }
    for (int i = 0; i < row; i++) {

        for (int j = 0; j < column; j++)

            matr_res[i][j] = num * matr[i][j];

    }

    for (int i = 0; i < row; i++) {

        for (int j = 0; j < column; j++)

            cout << matr_res[i][j] << " ";

        cout << endl;

    }
    return matr_res;

}
double** matrix::mult(matrix matrix_1, matrix matrix_2) {

    if (matrix_1.column == matrix_2.row) { //умова, що кількість стовпців першої матриці = кількості рядків другої матриці

        double** mat1;

        mat1 = new double* [matrix_1.row];

        for (int i = 0; i < matrix_1.row; i++)

            mat1[i] = new double[matrix_2.column];

        float sum = 0.0;

        for (int i = 0; i < matrix_1.row; i++) {

            for (int j = 0; j < matrix_2.column; j++) {

                for (int k = 0; k < matrix_1.column; k++) {

                    sum += matrix_1.matr[i][k] * matrix_2.matr[k][j];

                }

                mat1[i][j] = sum;

                sum = 0;

            }
        }

        cout << "Multiplication done!" << endl;

        for (int i = 0; i < matrix_1.row; i++) {

            for (int j = 0; j < matrix_2.column; j++)

                cout << mat1[i][j] << " ";

            cout << endl;

        }
        return mat1;

    }

    else {
        cout << "Dimensions error!" << endl;
        return 0;
    }



}
double matrix::det() {

    if (row == column) {

        if (row == 1)

        {

            return matr[0][0];

        }

        else if (row == 2)
        {


            return matr[0][0] * matr[1][1] - matr[0][1] * matr[1][0];

        }

        else if (row == 3) {

            return (matr[0][0] * (matr[1][1] * matr[2][2] - matr[2][1] * matr[1][2])) - (matr[0][1] * (matr[1][0] * matr[2][2] - matr[1][2] * matr[2][0])) + (matr[0][2] * (matr[1][0] * matr[2][1] - matr[1][1] * matr[2][0]));

        }

        else {

            double sum = 0;

            double** z;

            z = new double* [row];

            for (int i = 0; i < row; i++) {

                z[i] = new double[row];
            }

            sum = det_for(matr, row);

            for (int i = 0; i < row; i++) {

                delete[] z[i];
            }
            delete[] z;
            cout << sum << endl;
            return sum;
        }
    }

    else {

        cout << "Error..Please enter an NxN matrix" << endl;

        return false;
    }

}
double matrix::det_for(double** z, int p) {

    double sum = 0, product;
    if (p == 3) {
        sum = (z[0][0] * (z[1][1] * z[2][2] - z[2][1] * z[1][2])) - (z[0][1] * (z[1][0] * z[2][2] - z[1][2] * z[2][0])) + (z[0][2] * (z[1][0] * z[2][1] - z[1][1] * z[2][0]));
    }
    else {
        int sign = 1, n, row;
        double** inner, member;
        inner = new double* [p - 1];
        for (int i = 0; i < p - 1; i++)
            inner[i] = new double[p - 1];
        for (int i = 0; i < p; i++) {
            row = 0;
            n = 0;
            for (int j = 0; j < p; j++) {
                for (int k = 0; k < p; k++) {
                    member = z[j][k];
                    if ((j == 0) || (k == i));
                    else {
                        inner[row][n] = member;
                        n = n + 1;
                        if (n == p - 1) {
                            n = 0;
                            row += 1;
                        }
                    }
                }
            }
            product = sign * z[0][i] * det_for(inner, p - 1);
            sum += product;
            sign = sign * -1;
        }
        for (int i = 0; i < p - 1; i++)
            delete[] inner[i];
        delete[] inner;
    }
    return sum;
}
void matrix::memory() {

    for (int i = 0; i < row; i++) {

        delete[] matr[i];

        delete[]elementary[i];
    }

    delete[] matr;

    delete[]elementary;
}
void matrix::single_matrix()
{

    for (int i = 0; i < row; i++) {

        for (int j = 0; j < row; j++) {

            if (i == j)

                elementary[i][j] = 1;

            else

                elementary[i][j] = 0;
        }
    }
}
double** matrix::transpose()
{

    double** mat1;

    mat1 = new double* [column];

    for (int i = 0; i < column; i++) {

        mat1[i] = new double[row];

    }

    for (int i = 0; i < column; ++i)
    {
        for (int j = 0; j < row; ++j)
        {
            mat1[i][j] = matr[j][i];

        }
    }
    cout << "Transposed matrix" << endl;
    for (int i = 0; i < column; ++i)
    {
        for (int j = 0; j < row; ++j)
        {
            cout<< mat1[i][j] <<" ";

        }
        cout << endl;
    }
    return mat1;

}
double** matrix::solve()
{
    double* res=new double[row];
    int col;

    if (row + 1 < column) {

        cout << "The equations don't have a unique solution" << endl;
        return 0;

    }
    else {

        col = column;

        column = row;

        if (det() == 0) {


            cout << "The equations don't have a unique solution" << endl;
            return 0;
        }
        else {

            single_matrix();

            double** mat1;

            mat1 = new double* [row];

            for (int i = 0; i < row; i++)

                mat1[i] = new double[col];

            for (int i = 0; i < row; i++) {

                for (int j = 0; j < col; j++)

                    mat1[i][j] = matr[i][j];
            }

            for (int j = 0; j < row; j++) {

                if (matr[j][j] == 0) {

                    for (int k = 0; k < row; k++) {

                        if (matr[k][j] != 0) {

                            for (int i = 0; i < col; i++) {

                                matr[j][i] = mat1[k][i];

                                matr[k][i] = mat1[j][i];
                            }

                            for (int i = 0; i < col; i++) {

                                mat1[j][i] = matr[j][i];

                                mat1[k][i] = matr[k][i];
                            }

                            k = row;
                        }
                    }
                }
            }
            for (int i = 0; i < row; i++) {

                for (int z = 0; z < row; z++) {

                    for (int j = 0; j < col; j++)

                        matr[z][j] = mat1[z][j];
                }
                for (int j = 0; j < col; j++) {

                    mat1[i][j] = (matr[i][j] / matr[i][i]);

                    if (j < row)

                        elementary[i][j] = (elementary[i][j] / matr[i][i]);
                }
                for (int k = 0; k < row; k++) {

                    for (int j = 0; j < col; j++) {

                        if (k == i);

                        else {

                            mat1[k][j] = (mat1[i][j] * -1 * matr[k][i]) + mat1[k][j];

                            if (j < row)

                                elementary[k][j] = (elementary[i][j] * -1 * matr[k][i]) + elementary[k][j];
                        }

                    }
                }

            }

            for (int i = 0; i < row; i++) {


                cout << "X" << i + 1 << " = " << mat1[i][col - 1] << endl;
                res[i] = mat1[i][col - 1];

            }
            cout << "The inverse matrix is.." << endl;

            for (int i = 0; i < row; i++) {

                for (int j = 0; j < row; j++)

                    cout << elementary[i][j] << " ";

                cout << endl;
            }
            return mat1;
        }
    }
    return 0;

}

matrix::~matrix()
{
}

