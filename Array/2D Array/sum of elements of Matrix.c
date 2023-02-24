#include<stdio.h>
int main(){
	int i,j,m,n;
	float total=0.0, average;
	printf("Enter the order of the matrix: ");
	scanf("%d %d",&m, &n);
	int arr[m][n];
	
	printf("Enter %d numbers(-ve, +ve or zero):\n", m*n);
	for (i=0;i<m;i++)
		for (j=0;j<n;j++)
				scanf("%d", &arr[i][j]);	
	
	for (i=0;i<m;i++){
		for (j=0;j<n;j++){
			total = total + arr[i][j];}}
	
	average = total/(m*n);
	printf("Sum of elements of Matrix= %.2f\n", total);
	printf("Average of all elements of Matrix= %.2f\n", average);
return 0;	
}
