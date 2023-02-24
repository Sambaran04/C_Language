#include <stdio.h>
#include <stdlib.h>

int size = 0;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int arr[], int size, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && arr[left] > arr[largest]){
        largest = left;
    }
    if (right < size && arr[right] > arr[largest]){
        largest = right;
    }
    if (largest != i){
        swap(&arr[i], &arr[largest]);
        heapify(arr, size, largest);
    }
}
void insert(int arr[], int item){
    if (size == 0){
        arr[0] = item;
        size = size + 1;
    }
    else{
        arr[size] = item;
        size = size + 1;
        for (int i = size / 2 - 1; i >= 0; i--){
            heapify(arr, size, i);
        }
    }
}
void delete (int arr[], int num){
    int i;
    for (i = 0; i < size; i++){
        if (num == arr[i])
            break;
    }
    swap(&arr[i], &arr[size - 1]);
    size = size - 1;
    for (int i = size / 2 - 1; i >= 0; i--){
        heapify(arr, size, i);
    }
}
void printheap(int arr[], int size){
    printf("Array representation of the heap: ");
    for (int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main(){
    int arr[100], choice, item, num, ch;
    do{
        printf("Enter the element you want to insert into the heap: ");
        scanf("%d", &item);
        insert(arr, item);
        printf("Enter 1 for inserting new element");
        printf("\nEnter 0 to main menu");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
    } while (choice == 1);
    while (1){
        printf("1.Insert an element in heap\n2.Delete an element from heap\n3.Display Heap Array\n4.Exit\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch){
        case 1:
            printf("Enter the element you want to insert into the heap: ");
            scanf("%d", &item);
            insert(arr, item);
            break;

        case 2:
            printf("Enter the element you want to delete from the heap: ");
            scanf("%d", &num);
            delete (arr, num);
            break;

        case 3:
            printheap(arr, size);
            break;

        case 4:
            exit(0);
            break;

        default:
            printf("Wrong choice! \n");
            break;
        }
    }

return 0;
}