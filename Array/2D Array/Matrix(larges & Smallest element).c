#include<stdio.h>
int main(){
	int i,j,m,n,max,min;
	printf("Enter the order of the matrix: ");
	scanf("%d %d",&m, &n);
	int arr[m][n];
	
	printf("Enter the elements of the Matrix: \n");
	for (i=0;i<m;i++)
		for (j=0;j<n;j++)
				scanf("%d", &arr[i][j]);	
	max = min = arr[0][0];
	for (i=0;i<m;i++){
		for (j=0;j<n;j++){
			if (arr[i][j]>max){
				max=arr[i][j];}
			if (arr[i][j]<min){
				min=arr[i][j];}}}
	
	printf("Largest element in the Matrix is: %d\n", max);
	printf("Smallest element in the Matrix is: %d", min);
return 0;	
}
