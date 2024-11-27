#include <stdio.h>
#include <stdlib.h>
#include "dot_product.h"

double **dot_product(int rows, int cols, double **matrix1, double **matrix2) {
    double **result = malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++) {
        result[i] = malloc(cols * sizeof(double));
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j]*matrix2[i][j];
        }
    }

    return result;
}