#include <stdio.h>
#include <stdlib.h>
#include "trace.h"

double trace(int rows, double **matrix) {
    
    double sum=0;

    for (int i = 0; i < rows; i++) {
        sum += matrix[i][i];
    }

    return sum;
}