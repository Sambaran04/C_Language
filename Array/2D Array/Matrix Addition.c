#include<stdio.h>   
int main()  
{  
    int m, n, i, j, a[10][10], b[10][10], c[10][10];  
    printf("Enter the number of rows of matrix: ");
    scanf("%d", &m);
    printf("Enter the number of columns of matrix: ");
    scanf("%d", &n);
    printf("Enter the elements of A matrix: \n");  
    for (i = 0; i < m; i++)  
        for (j = 0; j < n; j++){
			scanf("%d", & a[i][j]);}
    printf("Enter the elements of B matrix: \n");  
    for (i = 0; i < m; i++)  
        for (j = 0; j < n; j++) {
			scanf("%d", & b[i][j]);  }
    printf("Addition of entered matries:-\n");  
    for (i = 0; i < m; i++)  
    {  
        for (j = 0; j < n; j++)  
        {  
            c[i][j] = a[i][j] + b[i][j];  
            printf("%d\t", c[i][j]);  
        }  
        printf("\n");  
    }  
    return 0;
}
