#include <stdio.h>
#include <stdlib.h>
#define size 100

int t[size][size], v[size], w[size];
int n, count = 0;

int max(int a, int b)
{
      return a > b ? a : b;
}

int knap(int i, int j)
{
      if (t[i][j] == -1)
      {
            count++; // Incrementing the count for the basic operation
            if (j < w[i])
                  t[i][j] = knap(i - 1, j);
            else
                  t[i][j] = max(knap(i - 1, j), v[i] + knap(i - 1, j - w[i]));
      }
      return t[i][j];
}

void tester()
{
      int m;
      printf("Enter number of items and sack capacity: ");
      scanf("%d %d", &n, &m);

      printf("Enter weights and values of items:\n");
      for (int i = 1; i <= n; i++)
            scanf("%d %d", &w[i], &v[i]);

      for (int i = 0; i <= n; i++)
      {
            for (int j = 0; j <= m; j++)
                  if (i == 0 || j == 0)
                        t[i][j] = 0;
                  else
                        t[i][j] = -1;
      }

      printf("The maximum profit: %d\n", knap(n, m));

      printf("DP Table:\n");
      for (int i = 0; i <= n; i++)
      {
            for (int j = 0; j <= m; j++)
                  printf("%d ", t[i][j]);
            printf("\n");
      }

      printf("Composition of items: ");
      for (int i = n; i > 0; i--)
      {
            if (t[i][m] != t[i - 1][m])
            {
                  printf("%d ", i);
                  m = m - w[i];
            }
      }
      printf("\n");
}

void plotter()
{
      tester();
      FILE *f1 = fopen("knapsack.txt", "a");
      fprintf(f1, "%d\t%d\n", n, count); // Writing n and count to the file
      fclose(f1);
}

int main()
{
      plotter();
      return 0;
}
