#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX], path[MAX], visited[MAX], count = 0;
int stack[MAX], top = -1;
int cycle;

void dfs(int n, int start)
{
	visited[start] = 1;
	path[start] = 1;
	for (int i = 0; i < n; i++)
	{
		count++;
		if (graph[start][i] && visited[i] == 1 && path[i] == 1)
		{
			cycle = 1;
			return;
		}
		if (graph[start][i] && visited[i] == 0)
			dfs(n, i);
	}
	path[start] = 0;
	stack[++top] = start;
}

void tester()
{
	int n;
	printf("Enter number of vertices : ");
	scanf("%d", &n);

	printf("Enter adj matrix : \n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			scanf("%d", &graph[i][j]);
		visited[i] = 0;
	}

	for (int i = 0; i < n; i++)
	{
		if (visited[i] == 0)
			dfs(n, i);

		if (cycle == 1)
		{
			printf("It has a loop, no topological sorting.\n");
			return;
		}
	}
	printf("Topological sorting ");
	while (top != -1)
		printf("-->%c ", stack[top--] + 65);
	printf("\n");
}

void plotter(int k)
{
	FILE *f1 = fopen("best.txt", "a");
	FILE *f2 = fopen("worst.txt", "a");

	int v;

	for (int i = 1; i <= 10; i++)
	{
		v = i;
		int **arr = (int **)malloc(v * sizeof(int *));
		for (int j = 0; j < v; j++)
			arr[j] = (int *)malloc(v * sizeof(int));

		if (k == 0)
		{
			for (int i = 0; i < v; i++)
			{
				for (int j = 0; j < v; j++)
				{
					if (i != j)
						arr[i][j] = 1;
					else
						arr[i][j] = 0;
				}
			}
		}

		if (k == 1)
		{
			for (int i = 0; i < v; i++)
			{
				for (int j = 0; j < v; j++)
					arr[i][j] = 0;
			}

			for (int i = 0; i < v - 1; i++)
				arr[i][i + 1] = 1;
		}

		// Copy arr to graph for processing
		for (int i = 0; i < v; i++)
		{
			for (int j = 0; j < v; j++)
				graph[i][j] = arr[i][j];
			visited[i] = 0;
			path[i] = 0;
		}

		top = -1;
		cycle = 0;

		count = 0;
		for (int i = 0; i < v; i++)
		{
			if (visited[i] == 0)
				dfs(v, i);
		}

		if (k == 0)
			fprintf(f2, "%d\t%d\n", v, count);
		else
			fprintf(f1, "%d\t%d\n", v, count);

		// Free allocated memory
		for (int i = 0; i < v; i++)
			free(arr[i]);
		free(arr);
	}

	fclose(f1);
	fclose(f2);
}

int main()
{
	tester();

	for (int i = 0; i < 2; i++)
		plotter(i);
	printf("\ndata added.\n");
	return 0;
}
