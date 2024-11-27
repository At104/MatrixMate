#include <stdio.h>
#include <stdlib.h>
#include "determinant.h"

// Function to calculate the determinant of a matrix
double determinant(int n, double **matrix) {
    if (n == 1) {
        return matrix[0][0]; // Base case for 1x1 matrix
    }
    if (n == 2) {
        // Base case for 2x2 matrix
        return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
    }
    double det = 0;

    for (int col = 0; col < n; col++) {
        // Create the minor matrix
        double **minor = (double **)malloc((n - 1) * sizeof(double *));
        for (int i = 0; i < n - 1; i++) {
            minor[i] = (double *)malloc((n - 1) * sizeof(double));
        }
        for (int i = 1; i < n; i++) { // Start from the second row
            int minor_col = 0;
            for (int j = 0; j < n; j++) {
                if (j != col){
                    minor[i - 1][minor_col] = matrix[i][j];
                    minor_col+=1;
                }

            }
            int sign = 1;
            if (col % 2 !=0){
                sign = -1;
            }

            det += (sign * matrix[0][col] * determinant (n-1, minor)); //recursivly break down minors further and further and continue to add to determinant
       }

        // Free the memory for the minor matrix
        for (int i = 0; i < n - 1; i++) {
            free(minor[i]);
        }
        free(minor);
    }
        return det;
}