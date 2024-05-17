#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

float **matrix(int feature_count, int value_count)
{
    float **arr = (float *)malloc(sizeof(float *) * feature_count);
    for (int i = 0; i < feature_count; i++)
    {
        arr[i] = (float *)malloc(sizeof(float) * value_count);
    }
    return arr;
}

float predict(float X1, float X2, float *_intercept, float *_coeff1, float *_coeff2)
{
    return (*_intercept) + ((*_coeff1) * X1) + ((*_coeff2) * X2);
}

float sigmoid_result(float prediction)
{
    float e = 2.71828;
    return (1 / (1 + pow(e, (-prediction))));
}

float gradient_descent(float parameters, float alpha, float y, float x, float y_pred)
{
    float new_parameters = (parameters) + alpha * (y - y_pred) * y_pred * (1 - y_pred) * x;
}

float log_loss(float Y, float Y_Pred)
{
    return (-Y * log(Y_Pred) + (1 - Y) * log(1 - Y_Pred));
}

void Logistic_Regression(float **X, float *Y, float *_coeff1, float *_coeff2, float *_intercept, float value_count, float feature_count)
{
    float prediction = 0.0f;
    float X1 = 0.0f;
    float X2 = 0.0f;
    float Y_Value = 0.0f;
    float sigmoid = 0.0f;
    for (int x = 0; x < 20; x++)
    {
        for (int y = 0; y < value_count; y++)
        {
            X1 = *(X[0] + y);
            X2 = *(X[1] + y);
            Y_Value = *(Y + y);
            prediction = predict(X1, X2, _intercept, _coeff1, _coeff2);
            sigmoid = sigmoid_result(prediction);
            *_coeff1 = gradient_descent(*_coeff1, 0.2, Y_Value, X1, sigmoid);
            *_coeff2 = gradient_descent(*_coeff2, 0.2, Y_Value, X2, sigmoid);
            *_intercept = gradient_descent(*_intercept, 0.2, Y_Value, 1, sigmoid);
        }
    }
}

int main()
{
    float **X = matrix(2, 10);
}