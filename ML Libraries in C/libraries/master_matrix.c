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

/*
Fill the array with random data for analysis
*/

void sequential_populate(float **arr, int feature_count, int value_count)
{
    for (int i = 0; i < feature_count; i++)
    {
        for (int j = 0; j < value_count; j++)
        {
            *(*(arr + i) + j) = j;
        }
    }
}

void display_array(float **arr, int feature_count, int value_count)
{
    for (int j = 0; j < value_count; j++)
    {
        for (int i = 0; i < feature_count; i++)
        {
            printf("%f \t", *(*(arr + i) + j));
        }
        printf("\n");
    }
}

void populate_features(float **arr, int feature_count, int value_count, float *values)
{
    for (int i = 0; i < value_count; ++i)
    {
        *(*(arr + feature_count) + i) = *(values + i);
    }
}

int main()
{
    float **arr = twoDArray(3, 3);
    float X1[3] = {1.0f, 2.0f, 3.0f};
    float X2[3] = {4.0f, 5.0f, 6.0f};
    float X3[3] = {7.0f, 8.0f, 9.0f};
    populate_features(arr, 0, 3, X1);
    populate_features(arr, 1, 3, X2);
    populate_features(arr, 2, 3, X3);
    display(arr, 3, 3);
}
