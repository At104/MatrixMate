MatrixMate: main.c input.h input.c adjoint.h adjoint.c determinant.h determinant.c inverse.h inverse.c cofactor.h cofactor.c transpose.h transpose.c scalar_multiplication.h scalar_multiplication.c trace.h trace.c add.h add.c subtract.h subtract.c matrix_multiplication.h matrix_multiplication.c
	gcc -o MatrixMate main.c input.c adjoint.c determinant.c inverse.c cofactor.c transpose.c scalar_multiplication.c trace.c add.c subtract.c matrix_multiplication.c

MatrixMateCov: main.c input.h input.c adjoint.h adjoint.c determinant.h determinant.c inverse.h inverse.c cofactor.h cofactor.c transpose.h transpose.c scalar_multiplication.h scalar_multiplication.c trace.h trace.c add.h add.c subtract.h subtract.c matrix_multiplication.h matrix_multiplication.c
	gcc -o MatrixMateCov --coverage main.c input.c adjoint.c determinant.c inverse.c cofactor.c transpose.c trace.c scalar_multiplication.c add.c subtract.c matrix_multiplication.c
