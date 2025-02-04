
/*
学籍番号: AJG23005
氏名: 中 天花
*/

//Add if necessary
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <cmath>

using namespace std;

int main () {

    /* input data for QR decomposition */
    double input_mat[][5] = {
        {2.3, -2.1, 8.0, 5.0, -4.1},
        {2.8, 1.3, 1.0, -9.2, -1.0},
        {1.1, 2.9, 3.1, -2.1, 5.1},
        {-2.1, -6.0, -2.1, 2.0, 3.0},
        {7.0, 0.5, -2.1, 2.0, -5.0},
    };

    /* print the input_mat before calling gramSchmidt_QRdecomposition */
    std::cout << "input_mat = " << std::endl;
    // write here...
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::cout << std::fixed << std::setprecision(3) << std::setw(6) << input_mat[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // Gram-Schmidt & QR decomposition
    // write here...
    double Q[5][5] = {0}, R[5][5] = {0}, QR[5][5] = {0}, diff[5][5] = {0};
    double EPSILON = 1e-10;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            Q[j][i] = input_mat[j][i];
        }
        for (int j = 0; j < i; j++) {
            for (int k = 0; k < 5; k++) {
                R[j][i] += Q[k][j] * input_mat[k][i];
            }
            for (int k = 0; k < 5; k++) {
                Q[k][i] -= R[j][i] * Q[k][j];
            }
        }
        for (int k = 0; k < 5; k++) {
            R[i][i] += Q[k][i] * Q[k][i];
        }
        R[i][i] = sqrt(R[i][i]);
        for (int k = 0; k < 5; k++) {
            Q[k][i] /= R[i][i];
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                QR[i][j] += Q[i][k] * R[k][j];
            }
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            diff[i][j] = input_mat[i][j] - QR[i][j];
            if (std::fabs(diff[i][j]) < EPSILON) {
            diff[i][j] = 0.0;
        }
        }
    }

    /* print the matrix Q resulting from gramSchmidt_QRdecomposition */
    std::cout << "Q = " << std::endl;
    // write here...
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::cout << std::fixed << std::setprecision(3) << std::setw(6) << Q[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    /* print the matrix R resulting from gramSchmidt_QRdecomposition */
    std::cout << "R = " << std::endl;
    // write here...
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::cout << std::fixed << std::setprecision(3) << std::setw(6) << R[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    /* print the matrix Q * R */
    std::cout << "Q * R = ?" << std::endl;
    // write here...
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::cout << std::fixed << std::setprecision(3) << std::setw(6) << QR[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    /* print Input_mat - (Q * R) */
    std::cout << "Input_mat - (Q * R) = ?" << std::endl;
    // write here...
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::cout << std::fixed << std::setprecision(3) << std::setw(6) << diff[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    return 0;
}
