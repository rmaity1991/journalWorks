#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

/* Creates a pointer to pointer 2D array with rows=value count and columns=feature_count
 */
int **twoDArray(int feature_count, int value_count)
{

    int **X = (int *)malloc(sizeof(int *) * feature_count);

    for (int i = 0; i < feature_count; i++)
    {
        *(X + i) = (int *)malloc(sizeof(int) * value_count);
    }

    return X;
}

/*
Fill the array with random data for analysis
*/

void sequential_populate(int **arr, int feature_count, int value_count)
{
    for (int i = 0; i < feature_count; i++)
    {
        for (int j = 0; j < value_count; j++)
        {
            *(*(arr + i) + j) = j;
        }
    }
}

void display_array(int **arr, int feature_count, int value_count)
{
    for (int j = 0; j < value_count; j++)
    {
        for (int i = 0; i < feature_count; i++)
        {
            printf("%d \t", *(*(arr + i) + j));
        }
        printf("\n");
    }
    printf("\n");
}

void populate_features(int **arr, int feature_count, int value_count, int *values)
{
    for (int i = 0; i < value_count; ++i)
    {
        *(*(arr + feature_count) + i) = *(values + i);
    }
}

int *return_feature_cols(int **arr, int feature_count, int value_count)
{
    int *result = (int *)malloc(sizeof(int) * value_count);
    for (int i = 0; i < value_count; ++i)
    {
        *(result + i) = *(*(arr + feature_count) + i);
    }

    return result;
}

void display_cols(int *arr, int value_count)
{
    for (int i = 0; i < value_count; ++i)
    {
        printf("%d \n", *(arr + i));
    }
    printf("\n");
}

int main()
{
    int **arr = twoDArray(3, 9);
    int X1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int X2[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int X3[] = {100, 200, 300, 400, 500, 600, 700, 800, 900};
    sequential_populate(arr, 3, 9);
    populate_features(arr, 0, 9, X1);
    populate_features(arr, 1, 9, X2);
    populate_features(arr, 2, 9, X3);
    display_array(arr, 3, 9);

    int *result = return_feature_cols(arr, 0, 9);
    display_cols(result, 9);
}
