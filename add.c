double **add(int rows, int cols, double matrix1[rows][cols], double matrix2[rows][cols]) {
    double **result = malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++) {
        result[i] = malloc(cols * sizeof(double));
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j]+matrix2[i][j];
        }
    }

    return result;
}