#include <stdio.h>

int min(int a, int b){
	if (a < b){
		return a;
	}
	else{
		return b;
	}
}
void merge(double arr[], int l, int mid, int r, int deadline[]){
	int i, j, k;
	int n1 = mid-l + 1;
	int n2 = r-mid;

	double L[n1], R[n2];
	int L_deadline[n1], R_deadline[n2];

	for (i=0; i<n1; i++){
		L[i] = arr[l + i];
		L_deadline[i] = deadline[l + i];
	}
	for (j=0; j<n2; j++){
		R[j] = arr[mid + 1 + j];
		R_deadline[j] = deadline[mid + 1 + j];
	}

	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2){
		if (L[i] >= R[j]){
			arr[k] = L[i];
			deadline[k] = L_deadline[i];
			i++;
		}
		else{
			arr[k] = R[j];
			deadline[k] = R_deadline[j];
			j++;
		}
		k++;
	}

	while (i < n1){
		arr[k] = L[i];
		deadline[k] = L_deadline[i];
		i++;
		k++;
	}
	while (j < n2){
		arr[k] = R[j];
		deadline[k] = R_deadline[j];
		j++;
		k++;
	}
}

void mergeSort(double arr[], int l, int r, int deadline[]){
	if (l < r){
		int m = l + (r - l) / 2;
		mergeSort(arr, l, m, deadline);
		mergeSort(arr, m + 1, r, deadline);
		merge(arr, l, m, r, deadline);
	}
}
int main(){
	int n, i, dmax;
	printf("Enter the number of jobs: ");
	scanf("%d", &n);
	int deadline[n];
	double profit[n];
	printf("Enter the Profits and Deadlines of the jobs: ");
	for (i = 0; i < n; i++){
		scanf("%lf %d", &profit[i], &deadline[i]);
	}
	printf("Enter the Maximum deadline: ");
	scanf("%d", &dmax);
	mergeSort(profit, 0, n - 1, deadline);
	int time_slot[dmax], j, k;
	for (i = 0; i < dmax; i++){
		time_slot[i] = -1;
	}
	double total_profit = 0.0;
	double selected_jobs_profit[dmax];
	for (i = 0; i < dmax; i++){
		selected_jobs_profit[i] = 0.0;
	}
	for (i = 0; i < n; i++){
		k = min(dmax, deadline[i]) - 1;
		while (k >= 0){
			if (time_slot[k] == -1){
				time_slot[k] = i;
				total_profit += profit[i];
				selected_jobs_profit[k] += profit[i];
				break;
			}
			k--;
		}
	}
	printf("\nSelected Jobs:\n");
	for (i = 0; i < dmax; i++)
	{
		if (time_slot[i] != -1){
			printf("Job %d with profit %.2f and deadline %d\n", time_slot[i] + 1, profit[time_slot[i]], deadline[time_slot[i]]);
		}
	}
	printf("\nSelected Jobs' Profits per deadline:\n");
	for (i = 0; i < dmax; i++){
		if (selected_jobs_profit[i] != 0){
			printf("Jobs with deadline %d have a total profit of %.2f\n", i + 1, selected_jobs_profit[i]);
		}
	}
	printf("\nTotal Profit: %.2f\n", total_profit);
	return 0;
}