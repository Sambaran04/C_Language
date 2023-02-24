#include<stdio.h>
int main()
{
    int m,i,j, n;              
    printf("Enter the number of rows and column: ");
    scanf("%d %d",&m,&n);   
    int arr[10][10];       
    printf("Enter the elements of the matrix: \n");
    for( i=0;i<m;i++)   
    {
        for( j=0;j<n;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    printf("\nThe elements in the matrix are: \n");
    for(i=0;i<m;i++)     
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    int brr[10][10];       
    for(i=0;i<m;i++)     
    {
        for(j=0;j<n;j++)
        {
            brr[j][i]=arr[i][j];    
        }
    }
    printf("\nAfter transpose the elements are: \n");
    for(i=0;i<m;i++)     
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",brr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
