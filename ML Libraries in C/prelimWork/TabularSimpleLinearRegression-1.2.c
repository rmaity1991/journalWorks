#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

/* Creates a pointer to pointer 2D array with rows=value count and columns=feature_count
 */
float **twoDArray(int feature_count, int value_count)
{

    float **X = (float *)malloc(sizeof(float *) * feature_count);

    for (int i = 0; i < feature_count; i++)
    {
        *(X + i) = (float *)malloc(sizeof(float) * value_count);
    }

    return X;
}

void populate(float **arr, int feature_count, int value_count)
{
    for (int i = 0; i < feature_count; i++)
    {
        for (int j = 0; j < value_count; j++)
        {
            *(*(arr + i) + j) = j;
        }
    }
}

void display(float **arr, int feature_count, int value_count)
{
    for (int i = 0; i < feature_count; i++)
    {
        for (int j = 0; j < value_count; j++)
        {
            printf("%f \t", *(*(arr + i) + j));
        }
        printf("\n");
    }
}

void populate_features(float **arr, int feature_count, int value_count, float *values)
{
    for (int i = 0; i < value_count; i++)
    {
        *((*arr + feature_count) + i) = *(values + i);
    }
}

int summation(float *arr, int length)
{
    float sum = 0.0f;
    for (int i = 0; i < length; i++)
    {
        sum += arr[i];
    }

    return sum;
}

void Linear_Regression(float **X, float *Y, int feature_count, int value_count, float *_coeff, float *_intercept)
{
    float XY_Summation, X2_Summation, Y2_Summation, Y_Summation = 0.0f;
    float X_Summation = 0.0f;
    // Calculate X*Y and put in tabulation data
    float **tabulationArray = twoDArray(3, value_count);

    for (int i = 0; i < feature_count; i++)
    {
        for (int j = 0; j < value_count; j++)
        {
            // printf("The value of X_Summation before is %f \n", X_Summation);
            *(tabulationArray[0] + j) = *(X[i] + j) * Y[j];
            *(tabulationArray[1] + j) = pow(*(X[i] + j), 2);
            *(tabulationArray[2] + j) = pow(Y[j], 2);
            X_Summation = (*(X[i] + j)) + X_Summation;
            // printf("The value of X_Summation after is %f \n", X_Summation);
            // printf("The value of x is %f \n", (*(*(X + i) + j)));
        }
    }
    XY_Summation = summation(tabulationArray[0], value_count);
    Y_Summation = summation(Y, value_count);
    X2_Summation = summation(tabulationArray[1], value_count);
    Y2_Summation = summation(tabulationArray[2], value_count);

    // printf("The XY Summation is %f \n", XY_Summation);
    // printf("The X2 Summation is %f \n", X2_Summation);
    // printf("The Y2 Summation is %f \n", Y2_Summation);
    // printf("The Y Summation is %f \n", Y_Summation);
    // printf("The X Summation is %f \n", X_Summation);

    *_intercept = (((Y_Summation * X2_Summation) - (X_Summation * XY_Summation)) / ((value_count * X2_Summation) - pow(X_Summation, 2)));

    *_coeff = (((value_count * XY_Summation) - (X_Summation * Y_Summation)) / ((value_count * X2_Summation) - pow(X_Summation, 2)));

    display(tabulationArray, 3, 5);
}

float *predict(float *X, int value_count, float *_coeff, float *_intercept)
{
    float *Y = (float *)malloc(sizeof(float) * value_count);
    // for (int i = 0; i < value_count; i++)
    // {
    //     printf("%f \t", X[i]);
    // }
    // printf("\n");
    for (int i = 0; i < value_count; i++)
    {
        Y[i] = (*_coeff) * X[i] + (*_intercept);
    }
    // for (int i = 0; i < value_count; i++)
    // {
    //     printf("%f \t", Y[i]);
    // }
    // printf("\n");
    return Y;
}

int main()
{
    float **X = twoDArray(1, 5);
    float X_0[5] = {2.0f, 4.0f, 8.0f, 12.0f, 16.0f};
    float X_Test[5] = {3.0f, 5.0f, 7.0f, 14.0f, 16.0f};
    float Y[5] = {5.0f, 9.0f, 17.0f, 25.0f, 33.0f};
    float *values = &X_0;
    populate_features(X, 0, 5, values);
    float _coeff = 0;
    float _intercept = 0;

    Linear_Regression(X, Y, 1, 5, &_coeff, &_intercept);

    printf("The slope is : %f \n", _coeff);
    printf("The intercept is : %f \n", _intercept);

    float *Y_Pred = predict(X_Test, 5, &_coeff, &_intercept);

    for (int i = 0; i < 5; i++)
    {
        printf("%f \t", Y_Pred[i]);
    }
}
