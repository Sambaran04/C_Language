#include <stdio.h>
int main()
{
    int i, j, arr[10][10], count = 0, pro;
    float m, n;
    printf("Enter the value of m:");
    scanf("%f", &m);
    printf("Enter the value of n:");
    scanf("%f", &n);
    printf("Enter the elements of the matrix:\n");
    pro = m * n / 2;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (arr[i][j] == 0)
            {
                count++;
            }
        }
    }
    if (count > pro)
    {
        printf("It is a sparse matrix");
    }
    else
    {
        printf("It is not a sparse matrix");
    }
}
