#include <stdio.h>
#include <stdlib.h>

int graph[100][100];
int count = 0, n;

void creatGraph()
{
      printf("Enter number of vertices : ");
      scanf("%d", &n);

      printf("Enter adj matrix : \n");
      for (int i = 0; i < n; i++)
      {
            for (int j = 0; j < n; j++)
                  scanf("%d", &graph[i][j]);
      }
}

void warshallsAlgo()
{
      creatGraph();

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

void main()
{
      warshallsAlgo();

      printf("Applying warshalls algo.\n");
      printf("Transitive closure matrix.\n");

      for (int i = 0; i < n; i++)
      {
            for (int j = 0; j < n; j++)
                  printf("%d ", graph[i][j]);
            printf("\n");
      }

      printf("Operation count : %d", count);
}
