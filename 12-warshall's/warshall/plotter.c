#include <stdio.h>
#include <stdlib.h>

int count = 0;
int graph[100][100];


void warshallsAlgo(int n)
{

      for (int k = 0; k < n; k++)
      {
            for (int i = 0; i < n; i++)
            {
                  if (graph[i][k] == 1)
                  {
                        for (int j = 0; j < n; j++)
                        {
                              count++;
                              if (graph[k][j] == 1)
                                    graph[i][j] = 1;
                        }
                  }
            }
      }
}

void plotter(int c)
{
      FILE *F1 = fopen("w_b.txt", "a");
      FILE *F2 = fopen("w_w.txt", "a");

      for (int n = 1; n <= 10; n++)
      {
            if (c == 1)
            {
                  for (int i = 0; i < n; i++)
                  {
                        for (int j = 0; j < n; j++)
                        {
                              if (i == j)
                                    graph[i][j] = 0;
                              else
                                    graph[i][j] = 1;
                        }
                  }
            }

            if (c == 0)
            {
                  for (int i = 0; i < n; i++)
                  {
                        for (int j = 0; j < n; j++)
                              graph[i][j] = 0;
                  }

                  for (int i = 0; i < n - 1; i++)
                        graph[i][i + 1] = 1;
                  graph[n - 1][0] = 1;
            }

            count = 0;
            warshallsAlgo(n);

            if (c == 0)
                  fprintf(F1, "%d\t%d\n", n, count);
            else
                  fprintf(F2, "%d\t%d\n", n, count);
      }
      fclose(F1);
      fclose(F2);
}

void main()
{
      for (int i = 0; i < 2; i++)
            plotter(i);
      printf("data has been added to file.\n");
}