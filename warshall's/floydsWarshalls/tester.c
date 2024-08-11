#include <stdio.h>
#include <stdlib.h>

int n, count = 0;
int graph[100][100];

void creatGraph()
{
      printf("Enter number of vertices : ");
      scanf("%d", &n);

      printf("enter adj matrix : ");
      for (int i = 0; i < n; i++)
      {
            for (int j = 0; j < n; j++)
                  scanf("%d", &graph[i][j]);
      }
}

void floydWarshalls()
{
      creatGraph();
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
}

void main()
{
      floydWarshalls();

      printf("Applying floyd warshalls algo.\n");
      printf("All pair shortest path matrix.\n");

      for (int i = 0; i < n; i++)
      {
            for (int j = 0; j < n; j++)
                  printf("%d ", graph[i][j]);
            printf("\n");
      }

      printf("operation count : %d", count);
}