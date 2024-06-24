#include <stdio.h>
#include <limits.h>

int MatrixChainOrder(int number_array[], int size)
{

    int i, j, k, L, q;
    int matrix[size][size];
    // cost is zero when multiplying one matrix.
    for (i = 1; i < size; i++)
        matrix[i][i] = 0;

    // L is chain length.
    for (L = 2; L < size; L++)
    {
        for (i = 1; i < size - L + 1; i++)
        {
            j = i + L - 1;
            matrix[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++)
            {
                q = matrix[i][k] + matrix[k + 1][j] + number_array[i - 1] * number_array[k] * number_array[j];
                if (q < matrix[i][j])
                    matrix[i][j] = q;
            }
        }
    }

    return m[1][size - 1];
}
int main()
{
    int size;
    printf("\n\nEnter the size of array:");
    scanf("%d", &size);
    int number_array[n];
    printf("\nEnter array elements:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &number_array[i]);
    }
    printf("\nMinimum number of multiplications are: %d \n\n", MatrixChainOrder(number_array, size));
    return 0;
}