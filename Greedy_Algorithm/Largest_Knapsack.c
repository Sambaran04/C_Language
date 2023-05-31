#include <stdio.h>
#include <stdlib.h>

void merge(double arr[], int l, int m, int r, double pw_ratio[])
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    double L[n1], R[n2];
    double L_pw_ratio[n1], R_pw_ratio[n2];
 
    for (i = 0; i < n1; i++) {
        L[i] = arr[l + i];
        L_pw_ratio[i] = pw_ratio[l + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
        R_pw_ratio[j] = pw_ratio[m + 1 + j];
    }
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L_pw_ratio[i] >= R_pw_ratio[j]) {
            arr[k] = L[i];
            pw_ratio[k] = L_pw_ratio[i];
            i++;
        }
        else {
            arr[k] = R[j];
            pw_ratio[k] = R_pw_ratio[j];
            j++;
        }
        k++;
    }
 
    while (i < n1) {
        arr[k] = L[i];
        pw_ratio[k] = L_pw_ratio[i];
        i++;
        k++;
    }
 
    while (j < n2) {
        arr[k] = R[j];
        pw_ratio[k] = R_pw_ratio[j];
        j++;
        k++;
    }
}
void mergeSort(double arr[], int l, int r, double pw_ratio[])
{
    if (l < r) {
        int m = l + (r - l) / 2;
 
        mergeSort(arr, l, m, pw_ratio);
        mergeSort(arr, m + 1, r, pw_ratio);
 
        merge(arr, l, m, r, pw_ratio);
    }
}

int main()
{
    int n, i;
    double M, profit = 0;
 
    printf("Enter the number of items: ");
    scanf("%d", &n);
 
    double p[n], w[n], x[n], pw_ratio[n];
 
    printf("Enter the profit and weight of the items:\n");
    for (i = 0; i < n; i++) {
        scanf("%lf %lf", &p[i], &w[i]);
        pw_ratio[i] = p[i] / w[i];
    }
 
    printf("Enter the maximum capacity of the knapsack: ");
    scanf("%lf", &M);
 
    mergeSort(pw_ratio, 0, n - 1, pw_ratio);
 
    for (i = 0; i < n; i++) {
        x[i] = 0.0;
    }
 
    for (i = 0; i < n; i++) {
        if (w[i] > M) {
            break;
        }
        x[i] = 1.0;
        M -= w[i];
        profit += p[i];
    }
   if (i <= n - 1) {
        x[i] = M / w[i];
        profit += x[i] * p[i];
    }
 
    printf("Selected items:\n");
    for (i = 0; i < n; i++) {
        printf("Item %d: %.2f units\n", i + 1, 1.0 * x[i]);
		}

printf("Total value: %.2f\n", profit);

return 0;
}

