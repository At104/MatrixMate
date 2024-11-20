#include <stdio.h>
#include <stdlib.h>
#include "transpose.h"

double **transpose(int rows, int cols, double **matrix) {
    // Allocate memory for the transposed matrix
    double **result = (double **)malloc(cols * sizeof(double *));
    for (int i = 0; i < cols; i++) {
        result[i] = (double *)malloc(rows * sizeof(double));
    }

    // Fill the transposed matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
    return result; // Return the transposed matrix
}