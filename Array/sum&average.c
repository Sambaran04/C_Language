#include<stdio.h>
int main(){
	int i,n;
	float total=0.0, average;
	printf("Enter the number of elements in an Array: ");
	scanf("%d", &n);
	int arr[n];
	
	printf("Enter %d numbers(-ve, +ve or zero):\n", n);
	for (i=0;i<n;i++){
		printf("Enter element [%d]: ", i);
		scanf("%d", &arr[i]);
	}
	for (i=0; i<n; i++){
		total +=arr[i];
	}
	average = total/n;
	printf("Sum of %d numbers= %.2f\n", n, total);
	printf("Average of all input numbers= %.2f\n", average);
return 0;	
}
