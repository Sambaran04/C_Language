#include<stdio.h>
void addition(int arr[10][10], int brr[10][10], int m, int n);
int main()
{
    int arr[10][10],brr[10][10],crr[10][10],m,n,i,j;
    printf("Enter the value of m:");
    scanf("%d",&m);
    printf("Enter the value of n:");
    scanf("%d",&n);
    printf("Enter the elements of the first matrix:\n");
    for (i=0;i<m;i++)
        for (j=0;j<n;j++)
            scanf("%d",&arr[i][j]);
        
    
    printf("Enter the elements of the second matrix(Sparse matrix):\n");
    for (i=0;i<m;i++)
        for (j=0;j<n;j++)
            scanf("%d",&brr[i][j]);
        
    
    printf("Sum of the two sparse matrix is(Sparse matrix):\n");
    for (i=0;i<m;i++){
        for (j=0;j<n;j++){
            crr[i][j] = arr[i][j] + brr[i][j];
            printf("%d ",crr[i][j]);
        }
        printf("\n");
    }
    
    
}

void addition(int arr[10][10], int brr[10][10], int m, int n)
{
    int crr[10][10], i,j;
    printf("Sum of the two sparse matrix is:");
    printf("%d",crr[i][j]);
}