#include <stdio.h>
#include <stdlib.h>
int *a, n, pivot, pi, p, n1, n2, i, j, k;
void bubble() //bubble sort
{
	for(i=0; i<n-1; i++){
        for(j=0; j<n-i; j++){
            if(a[j]>a[j+1])
            {
                k=a[j];
                a[j]=a[j+1];
                a[j+1]=k;
            }
        }
    }
}
void select() //selection sort
{
	for(i=0 ; i<n-1; i++){
        for(j=i+1; j<n; j++){
            if(a[i]>a[j]){
                k=a[i];
		        a[i]=a[j];
		        a[j]=k;
            }
        }
    }
}
void insert() //insertion sort
{
	for(i=0; i<n; i++)
	{
		k=a[i];
		j=i-1;
		while(k<a[j] && j>=0)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=k;
	}
}
int partition(int low, int high) //partition point for quick sort
{
	pivot = a[high];
  	i = (low - 1);
  	for (j = low; j < high; j++) 
  	{
    	if (a[j] <= pivot) 
		{
    	  i++;
    	  k=a[i];
    	  a[i]=a[j];
    	  a[j]=k;
    	}
  	}
  	k=a[i+1];
    a[i+1]=a[high];
    a[high]=k;
  	return (i + 1);
}
void quick(int low, int high) //quick sort
{
	if (low < high) 
	{
    	pi = partition(low, high);
    	quick(low, pi - 1);
    	quick( pi + 1, high);
	}
}
void merge(int p, int q, int r) //merges the sub-arrays
{
  	n1 = q - p + 1;
  	n2 = r - q;
  	int L[n1], M[n2];
  	for (i = 0; i < n1; i++)
    L[i] = a[p + i];
  	for (j = 0; j < n2; j++)
    M[j] = a[q + 1 + j];
  	i = 0;
  	j = 0;
  	k = p;
  	while (i < n1 && j < n2) 
	{
    	if (L[i] <= M[j]) 
		{
      		a[k] = L[i];
      		i++;
    	} 	
		else 
		{
      		a[k] = M[j];
      		j++;
    	}
    	k++;
  	}
  	while (i < n1)
  	{
    	a[k] = L[i];
    	i++;
    	k++;
  	}
  	while (j < n2) 
	{
    	a[k] = M[j];
    	j++;
    	k++;
  	}
}
void mergeSort(int l, int r) //merge sort
{
  	if (l < r) 
  	{
    	int m = l + (r - l) / 2;
    	mergeSort(l, m);
    	mergeSort(m + 1, r);
    	merge(l, m, r);
  	}
}
int main()
{
	int ch;
	printf("Enter number of elements: ");
	scanf("%d", &n);
	a= (int *)malloc(n*sizeof(int)); //dynamic memory allocation
	for(i=0 ; i<n; i++)
	{
		printf("Enter element for position %d: ", i+1);
		scanf("%d", &a[i]); //input size of array
	}
	
	printf("\nUn-sorted Array: ");
	for(i=0; i<n; i++)
	printf("%d ", a[i]);
	printf("\n\n1)Bubble sort\n2)Selection sort\n3)Insertion sort\n");
	printf("4) Quick sort\n5) Merge sort\nEnter choice: ");
	scanf("%d", &ch); //user's choice
	switch(ch) //switch case
	{
		case 1: bubble();
		        break;
		case 2: select();
		        break;
		case 3: insert();
		    	break;
		case 4: quick(0, n-1);
		        break;
		case 5: mergeSort(0, n-1);
		        break;
		default: printf("Wrong choice..");
	}
	printf("\nSorted Array: ");
	for(i=0; i<n; i++)
	printf("%d ", a[i]); //printing aorted array
	free(a); //freeing pointer a
	return 0;
}