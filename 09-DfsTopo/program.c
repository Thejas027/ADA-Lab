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

int main()
{
	tester();
	return 0;
}
