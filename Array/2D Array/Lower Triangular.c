#include <stdio.h>

int main()
{
    int array[10][10];
    int i, j, isLower, max_rows, max_cols, sum = 0;

    /* Input elements in matrix from user */
    printf("Enter the dimension of the matrix:");
    scanf("%d %d", &max_rows, &max_cols);
    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < max_rows; i++)
    {
        for (j = 0; j < max_cols; j++)
        {
            scanf("%d", &array[i][j]);
        }
    }
    isLower = 1;
    for (i = 0; i < max_rows; i++)
    {
        for (j = 0; j < max_cols; j++)
        {
            /*
             * If elements above the main diagonal (row>col)
             * is not equal to zero then it is not lower triangular matrix
             */
            if (i < j && array[i][j] != 0)
            {
                isLower = 0;
            }
        }
    }

    if (isLower == 1)
    {
        printf("\nThe matrix is a Lower triangular matrix.\n");

        for (i = 0; i < max_rows; i++)
        {
            for (j = 0; j < max_cols; j++)
            {
                printf("%d ", array[i][j]);
            }

            printf("\n");
        }
    }
    else
    {
        printf("\nThe matrix is not a Lower triangular matrix.");
    }

    for (i = 0; i < max_rows; i++)
    {
        for (j = 0; j < max_cols; j++)
        {
            sum += array[i][j];
        }
    }
    printf("Sum of all the elements of the matrix is:%d", sum);

    return 0;
}
