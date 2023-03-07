#include<stdio.h>
int BS(int A[], int low, int high, int key){
    if (low<high){
        int mid = (low+high)/2;
        if (A[mid]==key){
            return mid;
        }
        else if(key>A[mid]){
            return BS(A, mid+1, high, key);
        }
        else{
            return BS(A, low, mid-1, key);
        }
    }
return -1;
}

int main(){
    int n;
    printf("Enter the array size: ");
    scanf("%d", &n);
    int A[n];
    printf("Enter the Element: ");
    for (int i=0; i<n; i++){
        scanf("%d", &A[i]);
    }
    int key;
    printf("Enter the Value: ");
    scanf("%d", &key);
    if (BS(A, 0, n, key)==-1){
        printf("The element is not in the array");
    }
    else{
        printf("The position of the element is: %d", BS(A,0, n, key));
    }
}