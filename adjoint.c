#include <stdio.h>
#include <stdlib.h>
#include "determinant.h"
#include "cofactor.h"
#include "transpose.h"

double **adjoint(int n, int **matrix) {
    // Step 1: Find the cofactor matrix
    double **cofactorMatrix = cofactor(n, matrix);

    // Step 2: Transpose the cofactor matrix
    double **adjointMatrix = transpose(n, cofactorMatrix);

    // Free the cofactor matrix
    for (int i = 0; i < n; i++) {
        free(cofactorMatrix[i]);
    }
    free(cofactorMatrix);

    return adjointMatrix;
}
