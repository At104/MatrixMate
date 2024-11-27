#include <stdio.h>
#include <stdlib.h>
#include "matrix_multiplication.h"

double **matrix_multiplication(int m, int n, int p, double **matrix1, double **matrix2) {
    double **result = malloc(m * sizeof(double *));
    for (int i = 0; i < m; i++) {
        result[i] = malloc(p * sizeof(double));
    }

    for (int i = 0; i < m; i++) { 
        for (int j = 0; j < p; j++) {
            double sum = 0;
            for (int k = 0; k<n; k++){
                sum += matrix1[m][n]*matrix2[n][p];
            }
            result[m][p] = sum;
        }
    }

    return result;
}