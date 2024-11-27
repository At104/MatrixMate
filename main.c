#include <stdio.h>
#include <stdlib.h>
#include "io.h"

int main(int argc, char *argv[]) {
    int rows = 0;
    int columns = 0;

    int rowsPTR = &rows;
    int columnsPTR = &columns;

    double *matrix1 = NULL;
    double *matrix2 = NULL;

    startInput(argc, argv, matrix1, matrix2);
    return 1;
}