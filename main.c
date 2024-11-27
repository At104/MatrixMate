#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "adjoint.h"
#include "cofactor.h"
#include "determinant.h"
#include "transpose.h"
#include "inverse.h"

/**
 * Main function
 */
int main(int argc, char *argv[]) {
    int rows = 0;
    int columns = 0;
    int choice = 0;

    double **matrix1 = NULL;
    double **matrix2 = NULL;

    handle_input(&matrix1, &matrix2, &rows, &columns, &choice);

    switch (choice) {
        case 1: {
            double **result = inverse(rows, matrix1);
            printf("Inverse of Matrix 1:\n");
            print_matrix(result, rows, rows);
            for (int i = 0; i < rows; i++) {
                free(result[i]);
            }
            free(result);
            break;
        }
        case 2: {
            double **result = adjoint(rows, matrix1);
            printf("Adjoint of Matrix 1:\n");
            print_matrix(result, rows, rows);
            for (int i = 0; i < rows; i++) {
                free(result[i]);
            }
            free(result);
            break;
        }
        case 3: {
            double **result = cofactor(rows, matrix1);
            printf("Co-Factors of Matrix 1:\n");
            print_matrix(result, rows, rows);
            for (int i = 0; i < rows; i++) {
                free(result[i]);
            }
            free(result);
            break;
        }
        case 4: {
            double **result = transpose(rows, columns, matrix1);
            printf("Transpose of Matrix 1:\n");
            print_matrix(result, columns, rows);
            for (int i = 0; i < columns; i++) {
                free(result[i]);
            }
            free(result);
            break;
        }
        /** 
         * //TODO: Implement the following functions
        case 5: {
            double trace_value = trace(rows, matrix1);
            printf("Trace of Matrix 1: %.3f\n", trace_value);
            break;
        }
        case 6: {
            double scalar;
            printf("Enter the scalar value: ");
            scanf("%lf", &scalar);
            double **result = scalar_multiplication(rows, columns, matrix1, scalar);
            printf("Scalar Multiplication of Matrix 1:\n");
            print_matrix(result, rows, columns);
            for (int i = 0; i < rows; i++) {
                free(result[i]);
            }
            free(result);
            break;
        }
        
        
        case 7: {
            double **result = add(rows, columns, matrix1, matrix2);
            printf("Addition of Matrix 1 and Matrix 2:\n");
            print_matrix(result, rows, columns);
            for (int i = 0; i < rows; i++) {
                free(result[i]);
            }
            free(result);
            break;
        }
        case 8: {
            double **result = subtract(rows, columns, matrix1, matrix2);
            printf("Subtraction of Matrix 1 and Matrix 2:\n");
            print_matrix(result, rows, columns);
            for (int i = 0; i < rows; i++) {
                free(result[i]);
            }
            free(result);
            break;
        }
        case 9: {
            double **result = multiply(rows, columns, matrix1, matrix2);
            printf("Dot Product of Matrix 1 and Matrix 2:\n");
            print_matrix(result, rows, columns);
            for (int i = 0; i < rows; i++) {
                free(result[i]);
            }
            free(result);
            break;
        }
        case 10: {
            double **result = cross_product(rows, columns, matrix1, matrix2);
            printf("Cross Product of Matrix 1 and Matrix 2:\n");
            print_matrix(result, rows, columns);
            for (int i = 0; i < rows; i++) {
                free(result[i]);
            }
            free(result);
            break;
        }
        */
        default:
            printf("Invalid choice\n");
            break;
    }

    // Free allocated memory
    for (int i = 0; i < rows; i++) {
        free(matrix1[i]);
        if (matrix2 != NULL) {
            free(matrix2[i]);
        }
    }
    free(matrix1);
    if (matrix2 != NULL) {
        free(matrix2);
    }

    return EXIT_SUCCESS;
}