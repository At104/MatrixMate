#include <stdio.h>
#include <stdlib.h>
#include "determinant.h"
#include "cofactor.h"

double **cofactor(int n, double **matrix) {
    // Allocate memory for the cofactor matrix
    double **result = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) {
        result[i] = (double *)malloc(n * sizeof(double));
    }

    // Compute the cofactor for each element
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            // Create the minor matrix for element at (row, col)
            double **minor = (double **)malloc((n - 1) * sizeof(double *));
            for (int i = 0; i < n - 1; i++) {
                minor[i] = (double *)malloc((n - 1) * sizeof(double));
            }

            // Fill the minor matrix by excluding current row and column
            int minor_row = 0;
            for (int i = 0; i < n; i++) {
                if (i != row) { // Include only rows other than 'row'
                    int minor_col = 0;
                    for (int j = 0; j < n; j++) {
                        if (j != col) { // Include only columns other than 'col'
                            minor[minor_row][minor_col] = matrix[i][j];
                            minor_col++;
                        }
                    }
                    minor_row++;
                }
            }

            // Calculate the determinant of the minor
            double minorDet = determinant(n - 1, minor);

            // Apply the sign factor (-1)^(row + col)
            int sign = 1;
                if ((col + row) % 2 !=0){
                    sign = -1;
                }

            result[row][col] = sign * minorDet;

            // Free memory for the minor matrix
            for (int i = 0; i < n - 1; i++) {
                free(minor[i]);
            }
            free(minor);
        }
    }
    // Return the cofactor matrix
    return result;
}
