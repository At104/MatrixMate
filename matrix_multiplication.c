#include <stdio.h>
#include <stdlib.h>
#include "matrix_multiplication.h"

double **matrix_multiplication(int rows1, int columns1, int rows2, double **matrix1, double **matrix2) {
    double **result = malloc(rows1 * sizeof(double *));
    for (int i = 0; i < rows1; i++) {
        result[i] = malloc(rows2 * sizeof(double));
    }

    for (int i = 0; i < rows1; i++) { 
        for (int j = 0; j < rows2; j++) {
            result[i][j] = 0;
            for (int k = 0; k<columns1; k++){
                result[i][j] += matrix1[i][k]*matrix2[k][j];
            }
        }
    }

    return result;
}