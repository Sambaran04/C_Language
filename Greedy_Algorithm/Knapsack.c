#include <stdio.h>
#include <stdlib.h>
struct Item{
    int profit, weight;
};
int cmp(const void *a, const void *b){
    struct Item *item1 = (struct Item *)a;
    struct Item *item2 = (struct Item *)b;
    double r1 = (double)item1->profit / (double)item1->weight;
    double r2 = (double)item2->profit / (double)item2->weight;
    if (r1 < r2)
        return 1;
    else if (r1 > r2)
        return -1;
    else
        return 0;
}
double fractionalKnapsack(int W, struct Item arr[], int N){
    qsort(arr, N, sizeof(struct Item), cmp);
    double finalvalue = 0.0;
    int i;
    for (i = 0; i < N; i++){
        if (arr[i].weight <= W){
            W -= arr[i].weight;
            finalvalue += arr[i].profit;
            printf("Select Item %d (Profit: %d, Weight: %d) - Fractional weight: 1.00\n", i+1, arr[i].profit, arr[i].weight);
        }else{
            double fraction = (double)W / (double)arr[i].weight;
            finalvalue += arr[i].profit * fraction;
            printf("Select Item %d (Profit: %d, Weight: %d) - Fractional weight: %.2lf\n", i+1, arr[i].profit, arr[i].weight, fraction);
            break;
        }
    }
    return finalvalue;
}
int main(){
    int i, W;
    printf("Enter the maximum weight capacity of the knapsack: ");
    scanf("%d", &W);
    int N;
    printf("Enter the number of items: ");
    scanf("%d", &N);
    struct Item *arr = (struct Item *)malloc(N * sizeof(struct Item));
    printf("Enter the profit and weight of each item:\n");
    for (i = 0; i < N; i++){
        printf("Item %d: ", i + 1);
        scanf("%d", &arr[i].profit);
        scanf("%d", &arr[i].weight);
    }
    double max_value = fractionalKnapsack(W, arr, N);
    printf("Maximum value that can be obtained: %.2lf\n", max_value);
    free(arr);
return 0;
}