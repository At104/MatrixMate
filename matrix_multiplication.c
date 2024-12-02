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
            result[i][j] = 0;
            for (int k = 0; k<n; k++){
                result[i][j] += matrix1[i][k]*matrix2[k][j];
            }
        }
    }

    return result;
}

/*int main(){
    int m = 2, n = 3, p = 2;

    double **matrix1 = malloc(m * sizeof(double *));
    for (int i = 0; i < m; i++) {
        matrix1[i] = malloc(n * sizeof(double));
    }
    matrix1[0][0] = 1; matrix1[0][1] = 2; matrix1[0][2] = 3;
    matrix1[1][0] = 4; matrix1[1][1] = 5; matrix1[1][2] = 6;

    // Allocate and initialize the second matrix (3x2)
    double **matrix2 = malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) {
        matrix2[i] = malloc(p * sizeof(double));
    }
    matrix2[0][0] = 7; matrix2[0][1] = 8;
    matrix2[1][0] = 9; matrix2[1][1] = 10;
    matrix2[2][0] = 11; matrix2[2][1] = 12;

    double **result = matrix_multiplication(m, n, p, matrix1, matrix2);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            printf("%6.2f ", result[i][j]);
        }
        printf("\n");
    }

    // Free allocated memory
    for (int i = 0; i < m; i++) free(matrix1[i]);
    free(matrix1);

    for (int i = 0; i < n; i++) free(matrix2[i]);
    free(matrix2);

    for (int i = 0; i < m; i++) free(result[i]);
    free(result);

    return 0;
}*/