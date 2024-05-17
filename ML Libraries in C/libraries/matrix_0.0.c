// Online C compiler to run C program online
#include<stdio.h>
#include<stdlib.h>

typedef struct matrix{
    int rows;
    int columns;
    int ** grid;
}mat;


int length(int *);
mat * createMatrix(int,int);
void initArray(mat *);
void display(mat * X);
void matrixFillRow(mat * ,int *, int);
void matrixFillCol(mat * ,int *,int);
mat * matrixAdd(mat *,mat *);
mat * matrixSub(mat *,mat *);
mat* matrixMul(mat * , mat * );
int * getRow(mat * ,int );
int * getColumn(mat *,int);
int vectorDot(int *, int *);
void vectorDisplay(int *data);

/*******************************************************************************************/

int main(){
    mat *X=createMatrix(4,3);

    int X1[5]={10,13,14,15,18};

    // matrixFillCol(X,X1,0);

}

/*******************************************************************************************/

int length(int * X){
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
    X->grid=(int*)malloc(X->columns*sizeof(int*));
    int i=0;
    while(i<=X->columns){
        X->grid[i]=(int*)malloc(sizeof(int)*X->rows);
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

void vectorDisplay(int *data){
    for(int i=0;i<length(data);i++){
        printf("%d \t",data[i]);
    }
    printf("\n");
    printf("*********************** \n");
}


void matrixFillRow(mat * X,int * data, int row){
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

void matrixFillCol(mat * X,int * data,int col){
    if(X->rows==length(data)){
        if(col<X->columns){
            for(int i=0;i<X->rows;i++){
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

int * getRow(mat * X,int row){
    
    if(row<X->rows){
        int *result=(int*)malloc(sizeof(int)*X->columns);
        for(int i=0;i<X->columns;i++){
           result[i]=X->grid[row][i];
        }
        return result;
    }
    
}

int * getColumn(mat * X,int col){
     
    if(col<X->columns){
        int *result=(int*)malloc(sizeof(int)*X->rows);
        for(int i=0;i<X->rows;i++){
           result[i]=X->grid[i][col];
        }
        return result;
    }  
}

int vectorDot(int *X, int *Y){
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