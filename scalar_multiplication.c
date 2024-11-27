#include <stdio.h>
#include <stdlib.h>
#include "scalar_multiplication.h"

double **scalar_multiplication(int rows, int cols, double scalar, double **matrix) {
    double **result = malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++) {
        result[i] = malloc(cols * sizeof(double));
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = scalar * matrix[i][j];
        }
    }

    return result;
}