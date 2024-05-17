#ifndef MATRIX_H
#define MATRIX_H

typedef struct matrix{
    int rows;
    int columns;
    double ** grid;
}mat;

int length(double *);
mat * createMatrix(int,int);
void initArray(mat *);
void display(mat *);
void matrixFillRow(mat * ,double *, int);
void matrixFillCol(mat * ,double *,int);
mat * matrixAdd(mat *,mat *);
mat * matrixSub(mat *,mat *);
mat* matrixMul(mat * , mat * );
double * getRow(mat * ,int );
double * getColumn(mat *,int);
double vectorDot(double *, double *);
void vectorDisplay(double *);


#endif