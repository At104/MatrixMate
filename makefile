MatrixMate: main.c io.h io.c
	gcc -o MatrixMate main.c io.c io.h

MatrixMateCov: main.c io.h io.c
	gcc -o MatrixMate --coverage main.c io.c io.h
