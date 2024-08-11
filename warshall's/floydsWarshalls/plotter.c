#include <stdio.h>
#include <stdlib.h>

int graph[100][100];
int count = 0;

void creatGraph(int n)
{
      for (int i = 0; i < n; i++)
      {
            for (int j = 0; j < n; j++)
            {
                  if (i == j)
                        graph[i][j] = 0;
                  else
                        graph[i][j] = rand();
            }
      }
}

void plotter()
{
      FILE *fp = fopen("floyd.txt", "a");

      for (int n = 2; n < 10; n++)
      {
            count = 0;
            creatGraph(n);
            int temp;

            for (int k = 0; k < n; k++)
            {
                  for (int i = 0; i < n; i++)
                  {
                        temp = graph[i][k];
                        for (int j = 0; j < n; j++)
                        {
                              if (graph[i][j] > temp)
                              {
                                    count++;
                                    if (temp + graph[k][j] < graph[i][j])
                                          graph[i][j] = temp + graph[k][j];
                              }
                        }
                  }
            }
            fprintf(fp, "%d\t%d\n", n, count);
      }
      fclose(fp);
}

void main()
{
      plotter();
      printf("data has been added to file.\n");
}