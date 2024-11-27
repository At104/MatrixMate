#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void output(double **matrix, int rows, int columns) {
    if (matrix == NULL) {
        return;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%.3f ", matrix[i][j]);
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

double **create_matrix(int rows, int columns) {
    double **matrix = NULL;
    char *token;

    matrix = malloc(rows * sizeof(double *));
    if (matrix == NULL) {
        fprintf(stderr, "Malloc failed");
    }

    for (int i = 0; i < rows; i++) {
        matrix[i] = malloc(columns * sizeof(double));
        if (matrix[i] == NULL) {
            fprintf(stderr, "Malloc failed");
        }
    }

    char lineBuffer[1000];

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
            matrix[i][j] = strtod(token, NULL);
            token = strtok(NULL, " ");
        }

    }

    return matrix;
}

double **create_matrix_file(int *rows, int *columns, const char *filen) {
    *rows = 0;
    *columns = 0;
    double **matrix = NULL;
    FILE *matrixFile = fopen(filen, "r");
    if(matrixFile == NULL) {
        fprintf(stderr, "File not open");
        fclose(matrixFile);
        return;
    }

    char lineBuffer[1000];    
    
    while (fgets(lineBuffer, sizeof(lineBuffer), matrixFile)) {
        (*rows)++;
    }

    if (rows > 0) {
        fseek(matrixFile, 0, SEEK_SET);
        if (fgets(lineBuffer, sizeof(lineBuffer), matrixFile)) {
            char *token = strtok(lineBuffer, " ");
            while (token != NULL) {
                (*columns)++;
                token = strtok(NULL, " ");
            }
        }
    }

    matrix = malloc((*rows) * sizeof(double *));

    for (int i = 0; i < (*rows); i++) {
        matrix[i] = malloc((*columns) * sizeof(double));
        if (matrix[i] == NULL) {
            fprintf(stderr, "Malloc failed");
        }
    }

    fseek(matrixFile, 0, SEEK_SET);
    for (int i = 0; i < *rows; i++) {
            for (int j = 0; j < *columns; j++) {
                // If there is error setting the data
                if (fscanf(matrixFile, "%lf", &matrix[i][j]) != 1) {
                    fprintf(stderr, "Problem while reading the data");
                    free(matrix);
                    fclose(matrixFile);
                    return NULL;
                }
            }
    }

    fclose(matrixFile);

    return matrix;
}

void startInput(int argc, char *argv[], double **matrix1, double **matrix2) {
    int choice = 0;
    int rows = 0;
    int columns = 0;
    int *rowsPTR = &rows;
    int *columnsPTR = &columns;

    choice = listOptions();

    if(argc == 1) {

        printf("How many rows and columns are there?\n");
        int result = scanf("%d %d", &rows, &columns);    

        if (choice <= 6) {
            matrix1 = create_matrix(rows, columns);
            output(matrix1, rows, columns);
        }
        else if (choice >= 7) {
            printf("MATRIX 1\n");
            matrix1 = create_matrix(rows, columns);
            printf("MATRIX 2\n");
            matrix2 = create_matrix(rows, columns);
            output(matrix1, rows, columns);
            output(matrix2, rows, columns);
        }
    }
    else if (argc == 2) {
        if (argv[1][1] == 'f') {
            if (choice <= 6) {
                matrix1 = create_matrix_file(rowsPTR, columnsPTR, "matrix1.txt");
                output(matrix1, rows, columns);
            }
            else if (choice >= 7) {
                matrix1 = create_matrix_file(rowsPTR, columnsPTR, "matrix1.txt");
                matrix2 = create_matrix_file(rowsPTR, columnsPTR, "matrix2.txt");
                output(matrix1, rows, columns);
                output(matrix2, rows, columns);
            }
        }
    }
    else {
        fprintf(stderr, "Usage: MatrixMate [flag]\n\n\t-f: Takes input from files instead of manually\n");
    }
}