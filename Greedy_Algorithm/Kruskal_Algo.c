#include <stdio.h>
#include <stdlib.h>

int comparator(const void* p1, const void* p2)
{
	const int(*x)[3] = p1;
	const int(*y)[3] = p2;

	return (*x)[2] - (*y)[2];
}

void makeSet(int parent[], int rank[], int n)
{
	for (int i = 0; i < n; i++) {
		parent[i] = i;
		rank[i] = 0;
	}
}

int find(int parent[], int component)
{
	if (parent[component] == component)
		return component;

	return parent[component]
		= find(parent, parent[component]);
}

void unionSet(int u, int v, int parent[], int rank[], int n)
{
	u = find(parent, u);
	v = find(parent, v);

	if (rank[u] < rank[v]) {
		parent[u] = v;
	}
	else if (rank[u] > rank[v]) {
		parent[v] = u;
	}
	else {
		parent[v] = u;
		rank[u]++;
	}
}
void kruskalAlgo(int n, int edge[n][3])
{
	qsort(edge, n, sizeof(edge[0]), comparator);

	int parent[n];
	int rank[n];

	makeSet(parent, rank, n);
	
	int minCost = 0;

	printf(
		"Following are the edges in the constructed MST\n");
	for (int i = 0; i < n; i++) {
		int v1 = find(parent, edge[i][0]);
		int v2 = find(parent, edge[i][1]);
		int wt = edge[i][2];
		if (v1 != v2) {
			unionSet(v1, v2, parent, rank, n);
			minCost += wt;
			printf("%d -- %d == %d\n", edge[i][0],
				edge[i][1], wt);
		}
	}

	printf("Minimum Cost Spanning Tree: %d\n", minCost);
}
int main()
{
	int edge[14][3] = { { 1, 7, 8 },
					{ 2, 6, 7 },
					{ 2, 3, 9 },
					{ 4, 1, 2 },
					{ 4, 3, 6 },
          			{6, 7, 9},
          			{7, 3, 4},
          			{7, 8, 9},
          			{8, 8, 1},
          			{8, 2, 3},
          			{9, 4, 5},
          			{10, 5, 6},
          			{11, 2, 8},
          			{14, 4, 6} };

	kruskalAlgo(9, edge);

	return 0;
}
