#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to create a matrix with given rows and columns
double **create_matrix(int rows, int columns) {
    double **matrix = (double **)malloc(rows * sizeof(double *));
    if (matrix == NULL) {
        fprintf(stderr, "Malloc failed");
        return NULL;
    }

    for (int i = 0; i < rows; i++) {
        matrix[i] = (double *)malloc(columns * sizeof(double));
        if (matrix[i] == NULL) {
            fprintf(stderr, "Malloc failed");
            for (int j = 0; j < i; j++) {
                free(matrix[j]);
            }
            free(matrix);
            return NULL;
        }
    }

    char lineBuffer[100];
    char *token;

    getchar(); // Consume the newline character left by scanf
    for (int i = 0; i < rows; i++) {
        printf("Enter row %d of your Matrix (space-separated values):\n", (i + 1));
        fgets(lineBuffer, sizeof(lineBuffer), stdin);

        token = strtok(lineBuffer, " ");
        for (int j = 0; j < columns; j++) {
            if (token == NULL) {
                for (int k = 0; k < rows; k++) {
                    free(matrix[k]);
                }
                free(matrix);
                fprintf(stderr, "token null\n");
                return NULL;
            }
            matrix[i][j] = strtod(token, NULL);
            token = strtok(NULL, " ");
        }
    }

    return matrix;
}
//TODO: Implement the two matrix operations, trace, and scalar multiplication
int listOptions() {
    printf("Enter matrix operation: (Just enter the number)\n");
    printf("---One Matrix Operations---\n");
    printf("(1) Inverse\n(2) Adjoint\n(3) Co-Factors\n(4) Transpose\n(5) Trace\n(6) Scalar Multiplication\n");
    printf("---Two Matrix Operations---\n");
    printf("(7) Matrix Addition\n(8) Matrix Subtraction\n(9) Dot Product\n(10) Cross Product\n");

    int choice = 0;
    int result = 0;
    const char *userInput;

    while (choice < 1 || choice > 10) {
        result = scanf("%d", &choice);
        if (result < 1) {
            fprintf(stderr, "Enter a number 1-10 to choose");
        }
    }

    return choice;
}
// Function to handle input of matrices
void handle_input(double ***matrix1, double ***matrix2, int *rows, int *columns, int *choice) {
    *choice = listOptions();

    printf("Enter the number of rows and columns:\n");
    scanf("%d %d", rows, columns);

    if (*rows <= 0 || *columns <= 0) {
        fprintf(stderr, "Invalid number of rows or columns\n");
        return;
    }

    if (*choice <= 6) {
        *matrix1 = create_matrix(*rows, *columns);
        if (*matrix1 == NULL) {
            fprintf(stderr, "Failed to create matrix1\n");
            return;
        }
        *matrix2 = NULL;
    } 
    else if (*choice >= 7 && *choice <= 10) {
        *matrix1 = create_matrix(*rows, *columns);
        if (*matrix1 == NULL) {
            fprintf(stderr, "Failed to create matrix1\n");
            return;
        }

        *matrix2 = create_matrix(*rows, *columns);
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