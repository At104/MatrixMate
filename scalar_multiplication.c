#include <stdio.h>
#include <stdlib.h>
#include "scalar_multiplication.h"

/**
 * Function to multiply a matrix by a scalar
 * @param rows Number of rows in the matrix
 * @param cols Number of columns in the matrix
 * @param scalar Scalar value to multiply the matrix by
 * @param matrix Matrix to multiply
 * @return The result of the scalar multiplication
 */
double **scalar_multiplication(int rows, int cols, double scalar, double **matrix) {
    double **result = malloc(rows * sizeof(double *)); //allocate space
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
