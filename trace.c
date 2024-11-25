double trace(int rows, double matrix[rows][rows]) {
    
    double sum=0;

    for (int i = 0; i < rows; i++) {
        sum += matrix[i][i];
    }

    return sum;
}