#include <stdio.h>
#include <stdlib.h>
#include "determinant.h"
#include "adjoint.h"
#include "transpose.h"

double **inverse(int n, int **matrix) {
    // Calculate the determinant
    double det = determinant(n, matrix);
    if (det == 0) {
        printf("The matrix has a determinant of 0 and cannot be inverted.\n");
        return NULL;
    }

    double **adjointMatrix = adjoint(n, matrix);

    double **result = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) {
        result[i] = (double *)malloc(n * sizeof(double));
    }

    // Divide the adjoint matrix by the determinant
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = adjointMatrix[i][j] / det;
        }
    }
    // Free the adjoint matrix
    for (int i = 0; i < n; i++) {
        free(adjointMatrix[i]);
    }
    free(adjointMatrix);

    return result;
