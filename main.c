#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "adjoint.h"
#include "cofactor.h"
#include "determinant.h"
#include "transpose.h"
#include "inverse.h"
#include "trace.h"
#include "scalar_multiplication.h"
#include "add.h"
#include "subtract.h"
#include "matrix_multiplication.h"

/**
 * Main function to handle input and call the appropriate function
 * @param argc Number of command line arguments
 * @param argv Command line arguments
 * @return EXIT_SUCCESS if the program runs successfully
 */
int main(int argc, char *argv[]) {
    // Initialize variables
    int rows = 0;
    int rows2 = 0;
    int columns = 0;
    int columns2 = 0;
    int choice = 0;

    double **matrix1 = NULL;
    double **matrix2 = NULL;
    // Display help message

    if (argc > 1 && strcmp(argv[1], "--help") == 0) {
        printf("Usage: ./MatrixMate\n");
        printf("This program performs various matrix operations.\n");
        printf("Options:\n");
        printf("  --help          Display this help message\n");
        printf("  1               Inverse of Matrix 1\n");
        printf("  2               Adjoint of Matrix 1\n");
        printf("  3               Co-Factors of Matrix 1\n");
        printf("  4               Transpose of Matrix 1\n");
        printf("  5               Trace of Matrix 1\n");
        printf("  6               Scalar Multiplication of Matrix 1\n");
        printf("  The user will then be prompted for the number of rows and columns in the matrix.\n");
        printf("  7               Addition of Matrix 1 and Matrix 2\n");
        printf("  8               Subtraction of Matrix 1 and Matrix 2\n");
        printf("  9               Multiplication of Matrix 1 and Matrix 2\n");
        return EXIT_SUCCESS;
    }
    // Handle input
    handle_input(&matrix1, &matrix2, &rows, &columns, &rows2, &columns2, &choice);

    /**
     * Switch statement to call the appropriate function based on the user's choice
     */
    switch (choice) {
        case 1: {
            if (rows != columns) {
                fprintf(stderr, "Matrix must be square to have an inverse.\n");
                return EXIT_FAILURE;
            }
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
            
            if (rows != columns) {
                fprintf(stderr, "Matrix must be square to have an adjoint.\n");
                return EXIT_FAILURE;
            }
            
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
            if (rows != columns) {
                fprintf(stderr, "Matrix must be square to have co-factors.\n");
                return EXIT_FAILURE;
            }
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
        
        
        case 5: {
            if (rows != columns) {
                fprintf(stderr, "Matrix must be square to have a trace.\n");
                return EXIT_FAILURE;
            }
            double trace_value = trace(rows, matrix1);
            printf("Trace of Matrix 1: %.3f\n", trace_value);         
            break;
        }
        case 6: {
            double scalar;
            printf("Enter the scalar value:\n");
            scanf("%lf", &scalar);
            double **result = scalar_multiplication(rows, columns, scalar, matrix1);
            printf("Scalar Multiplication of Matrix 1:\n");
            print_matrix(result, rows, columns);
            for (int i = 0; i < rows; i++) {
                free(result[i]);
            }
            free(result);
            break;
        }
        
        case 7: {
            if (rows != rows2 || columns != columns2) {
                fprintf(stderr, "Matrix 1 and Matrix 2 must have the same dimensions for addition.\n");
                return EXIT_FAILURE;
            }
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
            if (rows != rows2 || columns != columns2) {
                fprintf(stderr, "Matrix 1 and Matrix 2 must have the same dimensions for subtraction.\n");
                return EXIT_FAILURE;
            }
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
            if (columns != rows2) {
                fprintf(stderr, "Matrix 1 columns must equal Matrix 2 rows for multiplication.\n");
                return EXIT_FAILURE;
            }
            double **result = matrix_multiplication(rows, columns, rows2, matrix1, matrix2);
            printf("Multiplication of Matrix 1 and Matrix 2:\n");
            print_matrix(result, rows, columns2);
            for (int i = 0; i < rows; i++) {
                free(result[i]);
            }
            free(result);
            break;
        }
        
        
        
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
