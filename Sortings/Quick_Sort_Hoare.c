#include <stdio.h>
int quickSort(int *arr, int low, int high)
{
int i = low, j = high;
int pivot = arr[(low + high) / 2];
while (i <= j)
{
while (arr[i] < pivot)
i++;
while (arr[j] > pivot)
j--;
if (i <= j)
{
int temp = arr[i];
arr[i] = arr[j];
arr[j] = temp;
i++;
j--;

}
}
if (low < j)
quickSort(arr, low, j);
if (i < high)
quickSort(arr, i, high);
return 0;
}

int main(void)
{
int i;
printf("Enter the size of the array: ");
int n;
scanf("%d", &n);
int arr[n];
int j;
printf("Enter the elements of the array: ");
for (i = 0; i < n; i++)
{
scanf("%d", &arr[i]);
}
int low = 0;
int high = n - 1;
int pivot = arr[high];
int k = low - 1;
for (j = low; j < high; j++)
{

if (arr[j] <= pivot)
{
k++;
int temp = arr[k];
arr[k] = arr[j];
arr[j] = temp;
}
}
int temp = arr[k + 1];
arr[k + 1] = arr[high];
arr[high] = temp;
int pi = k + 1;
quickSort(arr, low, pi - 1);
quickSort(arr, pi + 1, high);
printf("After quick sort:\n");
for (i = 0; i < n; i++)
{
printf("%d ", arr[i]);
}
return 0;
}