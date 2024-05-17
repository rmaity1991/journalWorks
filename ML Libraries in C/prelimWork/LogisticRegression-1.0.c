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

float predict(float X, float *_coeff, float *_intercept)
{
    float e = 2.71828f;
    float y = (*_coeff * (X)) + (*_intercept);
    return (1 / (1 + pow(e, y)));
}

float error(float Y, float Y_Pred)
{
    return (Y - Y_Pred);
}

float Gradient_Descent(float coeff_error, float intercept_error, float alpha, float value_count, float *_coeff, float *_intercept)
{
    *_coeff = (*_coeff) + alpha * (1 / value_count) * (coeff_error);
    *_intercept = (*_intercept) + alpha * (1 / value_count) * (intercept_error);
}

float mean_square_error(float *Y_Pred, float *Y, float value_count)
{
    float error = 0.0f;
    for (int i = 0; i < value_count; i++)
    {
        error += pow((Y[i] - Y_Pred[i]), 2);
    }

    return error / value_count;
}

void Logistic_Regression(float **X, float *Y, float *_coeff, float *_intercept, int feature_count, int value_count)
{

    float **calculation_array = twoDArray(3, value_count);
    float coeff_error_summation = 0.0f;
    float intercept_error_summation = 0.0f;
    float mse = 0.0f;
    // Loop For Iterations
    for (int a = 0; a < 500; a++)
    {
        // printf("The slope is : %f \n", *_coeff);
        // printf("The intercept is : %f \n", *_intercept);
        // Loop for predictions and error calculations
        for (int b = 0; b < value_count; b++)
        {
            // predictions
            float value = *(X[0] + b);
            *(calculation_array[0] + b) = predict(value, _coeff, _intercept);
            // errors in calculations
            *(calculation_array[1] + b) = error(Y[b], (*(calculation_array[0] + b)));
            *(calculation_array[2] + b) = error(Y[b], (*(calculation_array[0] + b))) * value;
        }
        // display(calculation_array,3,value_count);
        intercept_error_summation = summation(calculation_array[1], value_count);
        coeff_error_summation = summation(calculation_array[2], value_count);
        mse = mean_square_error(calculation_array[0], Y, value_count);
        // printf("The current mean square error is %f \n", mse);
        Gradient_Descent(coeff_error_summation, intercept_error_summation, 0.02f, value_count, _coeff, _intercept);
    }
}

int main()
{
    float **X = twoDArray(1, 7);
    float X_0[7] = {-3.0f, -2.0f, -1.0f, 0.0f, 1.0f, 2.0f, 3.0f};
    float Y[7] = {0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f};
    populate_features(X, 0, 7, X_0);
    float _coeff1 = 0.0f;

    float _intercept1 = 0.0f;

    Logistic_Regression(X, Y, &_coeff1, &_intercept1, 1, 7);
    printf("The slope with GD is : %f \n", _coeff1);
    printf("The intercept with GD is : %f \n", _intercept1);
}
