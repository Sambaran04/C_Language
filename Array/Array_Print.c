#include<stdio.h>
int main(){
	int i,n, arr[100];
	printf("Enter the number of elements in an array: ");
	scanf("%d", &n);
	printf("Enter the value of array: \n");
	for (i=0;i<n;i++){
		printf("Enter the element[%d]: ", i);
		scanf("%d", &arr[i]);
	}
	printf("The array is: ");
	for (i=0;i<n;i++){
		printf("%d ", arr[i]);}

return 0;
}
