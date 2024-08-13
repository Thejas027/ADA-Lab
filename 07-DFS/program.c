#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX], visited[MAX], isCyclic = 0;
int path[MAX];
int dfsCount = 0, count = 0, dcount = 0;
int d;

void dfs(int n, int start, int parent)
{
      visited[start] = 1;
      count++;
      printf("-->%c", start + 65);
      path[start] = 1;

      for (int i = 0; i < n; i++)
      {
            if (d == 1)
            {
                  if (i != parent && graph[start][i] && visited[i] && path[i])
                        isCyclic = 1;
            }
            else
            {
                  if (i != parent && graph[start][i] && visited[i])
                        isCyclic = 1;
            }
            dcount++;
            if (graph[start][i] && !visited[i])
                  dfs(n, i, start);
      }
      path[start] = 0;
}

void tester()
{
      int n;
      printf("Enter number of vertices: ");
      scanf("%d", &n);

      printf("Enter adj matrix:\n");
      for (int i = 0; i < n; i++)
      {
            for (int j = 0; j < n; j++)
                  scanf("%d", &graph[i][j]);
      }

      printf("Enter 1 if it's a directed graph: ");
      scanf("%d", &d);

      printf("Adjacency Matrix:\n");
      for (int i = 0; i < n; i++)
      {
            for (int j = 0; j < n; j++)
                  printf("%d\t", graph[i][j]);
            printf("\n");
      }

      isCyclic = 0;
      dcount = 0;
      count = 0;
      dfsCount = 0;

      for (int i = 0; i < n; i++)
      {
            visited[i] = 0;
            path[i] = 0;
      }

      printf("DFS traversal:\n");
      for (int i = 0; i < n; i++)
      {
            if (!visited[i])
            {
                  printf("Starting DFS from vertex %c\n", i + 65);
                  dfs(n, i, -1);
                  dfsCount++;
            }
      }

      if (count == n)
            printf("\nThe graph is connected.\n");
      else
      {
            printf("The graph is not connected.\n");
            printf("The number of connected components: %d\n", dfsCount);
      }

      if (isCyclic)
            printf("Graph is cyclic\n");
      else
            printf("Graph is not cyclic\n");
}

void plotter(int k)
{
      int v;
      FILE *f1 = fopen("best.txt", "a");
      FILE *f2 = fopen("worst.txt", "a");

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
                  for (int j = 0; j < v - 1; j++)
                        graph[j][j + 1] = 1;
            }

            dfsCount = 0, dcount = 0, count = 0, isCyclic = 0;
            dfs(v, 0, -1);
            dfsCount++;

            int start = 1;

            while (count != v)
            {
                  if (!visited[start])
                  {
                        dfs(v, start, -1);
                        dfsCount++;
                  }
                  start++;
            }
            if (k == 0)
                  fprintf(f2, "%d\t%d\n", v, dcount);
            else
                  fprintf(f1, "%d\t%d\n", v, dcount);
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
      printf("data entered to file.\n");
      return 0;
}
