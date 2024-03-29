#include<stdio.h>

void merge(int arr[], int l, int mid, int r){
    int n1 = mid-l+1;
    int n2 = r-mid;
    int a[n1], b[n2];
    for (int i=0; i<n1; i++){
        a[i]=arr[l+i];
    }
    for (int i=0; i<n2; i++){
        b[i]=arr[mid+1+i];
    }
    int i=0, j=0, k=l;
    while (i<n1 && j<n2){
        if (a[i]<b[j]){
            arr[k]=b[j];
            k++; j++;
        }
        else{
            arr[k]=a[i];
            k++; i++;
        }
    }
    while (i<n1){
        arr[k]=a[i];
        k++; i++;
    }
    while (j<n2){
        arr[k]=b[j];
        k++; j++;
    }
}

void mergesort(int arr[], int l, int r){
    if (l<r){
        int mid = (l+r)/2;
        mergesort(arr, l, mid);
        mergesort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }
}

int main(){
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the array elements: ");
    for (int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    mergesort(arr, 0, n-1);
    printf("Your sorted array is: ");
    for (int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
return 0;
}