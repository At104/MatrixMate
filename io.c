#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void output(double *matrix, int rows, int columns) {
    if (matrix == NULL) {
        return;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%.3f ", matrix[i * (columns) + j]);
        }
        printf("\n");
    }
}  

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

double *create_matrix(int rows, int columns) {
    double *matrix = NULL;
    char *token;

    matrix = malloc(rows * columns * sizeof(double));
    if (matrix == NULL) {
        fprintf(stderr, "Malloc failed");
    }

    char lineBuffer[100];

    getchar();
    for(int i = 0; i < rows; i++) {
        printf("Enter row %d of your Matrix\n", (i+1));
        fgets(lineBuffer, sizeof(lineBuffer), stdin);

        token = strtok(lineBuffer, " ");
        for (int j = 0; j < columns; j++) {
            if (token == NULL) {
                free(matrix);
                fprintf(stderr, "token null\n");
                return;
            }
            matrix[i * (columns) + j] = strtod(token, NULL);
            token = strtok(NULL, " ");
        }

    }

    return matrix;
}

void startInput(int argc, char *argv[], double *matrix1, double *matrix2) {
    int choice = 0;
    int rows = 0;
    int columns = 0;

    if(argc == 1) {
        choice = listOptions();

        printf("How many rows and columns are there?\n");
        int result = scanf("%d %d", &rows, &columns);    

        if (choice <= 6) {
            matrix1 = create_matrix(rows, columns);
        }
        else if (choice >= 7) {
            printf("MATRIX 1\n");
            matrix1 = create_matrix(rows, columns);
            printf("MATRIX 2\n");
            matrix2 = create_matrix(rows, columns);
        }
    }
    else if (argc == 2) {
        if (argv[1][1] == 'f') {
            printf("File flag\n");
        }
    }
    else {
        fprintf(stderr, "Usage: MatrixMate [flag]\n\n\t-f: Takes input from files instead of manually\n");
    }
}