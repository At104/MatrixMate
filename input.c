#include <stdio.h>
#include <stdlib.h>
#include "input.h"

// Function to create a matrix with given rows and columns
double **create_matrix(int rows, int columns) {
    double **matrix = (double **)malloc(rows * sizeof(double *));
    if (matrix == NULL) {
        fprintf(stderr, "Malloc failed\n");
        return NULL;
    }

    for (int i = 0; i < rows; i++) {
        matrix[i] = (double *)malloc(columns * sizeof(double));
        if (matrix[i] == NULL) {
            fprintf(stderr, "Malloc failed\n");
            for (int j = 0; j < i; j++) {
                free(matrix[j]);
            }
            free(matrix);
            return NULL;
        }
    }

    return matrix;
}

// Function to list options
int listOptions() {
    printf("Enter matrix operation: (Just enter the number)\n");
    printf("---One Matrix Operations---\n");
    printf("(1) Inverse\n(2) Adjoint\n(3) Co-Factors\n(4) Transpose\n(5) Trace\n(6) Scalar Multiplication\n");
    printf("---Two Matrix Operations---\n");
    printf("(7) Matrix Addition\n(8) Matrix Subtraction\n(9) Matrix Multiplication\n");

    int choice = 0;
    int result = 0;

    while (choice < 1 || choice > 9) {
        result = scanf("%d", &choice);
        if (result==EOF){
            exit(0);
        }
        if (result < 1) {
            fprintf(stderr, "Enter a number 1-9 to choose\n");
        }
    }

    return choice;
}

// Function to handle input of matrices
void handle_input(double ***matrix1, double ***matrix2, int *rows, int *columns, int *rows2, int *columns2, int *choice) {
    *choice = listOptions();

    printf("Enter the number of rows and columns for Matrix 1: ");
    scanf("%d %d", rows, columns);

    if (*choice <= 6) {
        *matrix1 = create_matrix(*rows, *columns);
        if (*matrix1 == NULL) {
            fprintf(stderr, "Failed to create matrix1\n");
            return;
        }
        *matrix2 = NULL;
    } else if (*choice >= 7 && *choice <= 9) {
        *matrix1 = create_matrix(*rows, *columns);
        if (*matrix1 == NULL) {
            fprintf(stderr, "Failed to create matrix1\n");
            return;
        }

        printf("Enter the number of rows and columns for Matrix 2: ");
        scanf("%d %d", rows2, columns2);

        *matrix2 = create_matrix(*rows2, *columns2);
        if (*matrix2 == NULL) {
            fprintf(stderr, "Failed to create matrix2\n");
            for (int i = 0; i < *rows; i++) {
                free((*matrix1)[i]);
            }
            free(*matrix1);
            return;
        }
    } else {
        fprintf(stderr, "Invalid choice\n");
        return;
    }

    // Read matrix1 values
    for (int i = 0; i < *rows; i++) {
        printf("Enter row %d of your Matrix 1 (space-separated values):\n", (i + 1));
        for (int j = 0; j < *columns; j++) {
            scanf("%lf", &(*matrix1)[i][j]);
        }
    }

    // Read matrix2 values if needed
    if (*matrix2 != NULL) {
        for (int i = 0; i < *rows2; i++) {
            printf("Enter row %d of your Matrix 2 (space-separated values):\n", (i + 1));
            for (int j = 0; j < *columns2; j++) {
                scanf("%lf", &(*matrix2)[i][j]);
            }
        }
    }
}

// Function to print a matrix
void print_matrix(double **matrix, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%.3f ", matrix[i][j]);
        }
        printf("\n");
    }
}
