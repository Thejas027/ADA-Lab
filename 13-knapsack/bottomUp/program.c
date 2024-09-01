#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int t[MAX][MAX], v[MAX], w[MAX], n, m;
int count = 0;
 
int max(int a, int b)
{
	return a > b ? a : b;
}

int knap(int m, int n)
{
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			if (i == 0 || j == 0)
				t[i][j] = 0;
			else
			{
				count++;
				if (j < w[i])
					t[i][j] = t[i - 1][j];
				else
					t[i][j] = max(t[i - 1][j], v[i] + t[i - 1][j - w[i]]);
			}
		}
	}
	return t[n][m];
}

void tester()
{
	printf("Enter number of items: ");
	scanf("%d", &n);

	printf("Enter the sack capacity: ");
	scanf("%d", &m);

	printf("wt\tval\n");
	for (int i = 1; i <= n; i++)
		scanf("%d %d", &w[i], &v[i]);

	printf("max value: %d\n", knap(m, n));

	// printing the table which has calculated the max profit value
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
			printf("%d ", t[i][j]);
		printf("\n");
	}

	printf("composition: ");
	for (int i = n; i > 0; i--)
	{
		if (t[i][m] != t[i - 1][m])
		{
			printf("%d\t", i);
			m = m - w[i];
		}
	}
	printf("\n");

	printf("%d\t%d\n", n, count);
}

// to get the graph run the program for different test case atleast for 3 to 4 to generate the graph, so on testing with diffrent test case it would give the graph
void plotter()
{
	FILE *f1 = fopen("knapsack.txt", "a");
	tester();
	fprintf(f1, "%d\t%d\n", n, count);
}

int main()
{
	plotter();
	return 0;
}
