#include "matrix.h"
#include<stdio.h>
#include<stdlib.h>

/*******************************************************************************************/

int length(double * X){
    int count=-1;
    for(int i=0;X[i]!='\0';i++){
        count++;
    }
    // printf("The array count is %d \n",count);
    return count;
}

mat * createMatrix(int rows, int cols){
    mat *X=(mat*)malloc(sizeof(mat));
    X->rows=rows;
    X->columns=cols;
    X->grid=(double*)malloc(sizeof(double*)*(X->columns));
    int i=0;
    while(i<=X->columns){
        *(X->grid+i)=(double*)malloc(sizeof(double)*X->rows);
        i++;
    }
    initArray(X);
    display(X);
    return X;
}

void initArray(mat * X){
    for(int i=0;i<X->rows;++i){
        for(int j=0;j<X->columns;++j){
            X->grid[i][j]=0;
        }
    }
}

void display(mat * X){
    for(int i=0;i<X->rows;i++){
        for(int j=0;j<X->columns;j++){
            printf("%d \t",X->grid[i][j]);
        }
        printf("\n");
    }
    printf("*********************** \n");

}

void vectorDisplay(double *data){
    for(int i=0;i<length(data);i++){
        printf("%d \t",data[i]);
    }
    printf("\n");
    printf("*********************** \n");
}


void matrixFillRow(mat * X,double * data, int row){
    if(X->columns==length(data)){
       if(row<X->rows){
            for(int i=0;i<X->columns;i++){
            X->grid[row][i]=data[i];
        }
       }
        else{
            printf("The specified row %d exceeds the total rows of matrix %d \n",row,X->rows);
        }
    }  
    else{
        printf("The column length of matrix %d and length of data %d do not match \n ",X->columns,length(data));
    }
}

void matrixFillCol(mat * X,double * data,int col){
    if(X->rows==length(data)){
        if(col<X->columns){
            for(int i=0;i<length(data);i++){
                X->grid[i][col]=data[i];
            }
        }
        else{
            printf("The specified row %d exceeds the total columns of matrix %d \n",col,X->rows);
        }
     }
     else{
        printf("The row length of matrix %d and length of data %d do not match \n ",X->rows,length(data));
     }
}

mat * matrixAdd(mat *X,mat *Y){
    if(X->rows==Y->rows){
        if(X->columns==Y->columns){
             mat *result=createMatrix(X->rows,X->columns);
            for(int i=0;i<X->rows;i++){
                for(int j=0;j<X->columns;j++){
                    result->grid[i][j]=X->grid[i][j]+Y->grid[i][j];
                }
        }
        return result;
        }
        else{
             printf("The column dimension do not match \n");
        }
    }
    else{
        printf("The row dimension do not match \n");
    }
}

mat * matrixSub(mat *X,mat *Y){
    if(X->rows==Y->rows){
        if(X->columns==Y->columns){
             mat *result=createMatrix(X->rows,X->columns);
            for(int i=0;i<X->rows;i++){
                for(int j=0;j<X->columns;j++){
                    result->grid[i][j]=X->grid[i][j]-Y->grid[i][j];
                }
        }
        return result;
        }
        else{
             printf("The column dimension do not match \n");
        }
    }
    else{
        printf("The row dimension do not match \n");
    }
}

mat* matrixMul(mat* X, mat* Y){
    if(X->columns==Y->columns && X->rows==Y->rows){
        mat * result=createMatrix(X->columns,Y->rows);
        for(int i=0; i<X->rows; i++)
        {
            for (int j=0; j<X->columns; j++)
            {
                result->grid[i][j] = 0;
                for(int k=0; k < X->rows; k++)
                    result->grid[i][j] += X->grid[i][k] * Y->grid[k][j];
                }
            }
            display(result);
            return result;
        }
        else{
            printf("The dimensions do not match..");
        }
    }

double * getRow(mat * X,int row){
    
    if(row<X->rows){
        double *result=(double*)malloc(sizeof(double)*X->columns);
        for(int i=0;i<X->columns;i++){
           result[i]=X->grid[row][i];
        }
        return result;
    }
    
}

double * getColumn(mat * X,int col){
     
    if(col<X->columns){
        double *result=(double*)malloc(sizeof(double)*X->rows);
        for(int i=0;i<X->rows;i++){
           result[i]=X->grid[i][col];
        }
        return result;
    }  
}

double vectorDot(double *X, double *Y){
    if(length(X)==length(Y)){
        int sum=0;
        for(int i=0;i<length(X);i++){
            sum+=X[i]*Y[i];
        }
        printf("The dot product is %d \n",sum);
        return sum;
    }
    else{
        printf("The dimensions are not equal.. \n");
    }
}