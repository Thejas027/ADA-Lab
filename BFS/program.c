#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int orderCount, count, isCyclic, bfsCount;
int graph[MAX][MAX], visited[MAX];

void bfs(int n, int start)
{
      int queue[MAX], parent[MAX];
      int parentNode, rear = -1, front = -1;
      visited[start] = 1;
      count++;
      queue[++rear] = start;
      parent[rear] = -1;

      while (rear != front)
      {
            start = queue[++front];
            parentNode = parent[front];
            printf("-->%c", start + 65);
            for (int i = 0; i < n; i++)
            {
                  orderCount++;
                  if (i != parent[i] && graph[start][i] && visited[i])
                        isCyclic = 1;

                  if (graph[start][i] && visited[i] != 1)
                  {
                        queue[++rear] = i;
                        count++;
                        visited[i] = 1;
                        parent[rear] = start;
                  }
            }
      }
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
      }

      bfsCount = 0, count = 0, orderCount = 0;
      printf("BFS traversal of graph : ");
      bfs(n, 0);
      int start = 1;

      if (count == n)
            printf("\nGraph is connected.\n");
      else
      {
            printf("\nGraph is not connected.\n");

            while (count != n)
            {
                  bfs(n, start);
                  printf("\n");
                  bfsCount++;
            }
            start++;
      }

      printf("Number of connected components : %d\n", bfsCount);
      if (isCyclic)
            printf("Graph has a cycle.\n");
      else
            printf("Graph has no cycle.\n");
}

void plotter(int k)
{
      FILE *f1 = fopen("best.txt", "a");
      FILE *f2 = fopen("worst.txt", "a");

      int v;

      for (int i = 1; i <= 10; i++)
      {
            v = i;
            if (k == 0)
            {
                  for (int j = 0; j < v; j++)
                  {
                        for (int k = 0; k < v; k++)
                        {
                              if (j != k)
                                    graph[j][k] = 1;
                              else
                                    graph[j][k] = 0;
                        }
                  }
            }
            else
            {
                  for (int j = 0; j < v; j++)
                  {
                        for (int k = 0; k < v; k++)
                              graph[j][k] = 0;
                  }

                  for (int j = 0; j < v; j++)
                        graph[j][j + 1] = 1;
            }

            bfsCount = 0, orderCount = 0, count = 0;
            bfs(v, 0);
            bfsCount++;
            int start = 1;

            while (count != v)
            {
                  if (!visited[start])
                  {
                        bfs(v, start);
                        bfsCount++;
                  }
                  start++;
            }

            if (k == 0)
                  fprintf(f2, "%d\t%d\n", v, orderCount);
            else
                  fprintf(f1, "%d\t%d\n", v, orderCount);
      }

      fclose(f1);
      fclose(f2);
}

int main()
{
      tester();

      printf("\n\n\nfrom plotter function just ignore it the output generating after this \n\n\n\n");
      for (int i = 0; i < 2; i++)
            plotter(i);
      printf("\ndata entered to file.\n");
      return 0;
}