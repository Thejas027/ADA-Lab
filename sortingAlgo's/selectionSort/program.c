#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count3;

void selectionSort(int *arr, int n)
{
      for (int i = 0; i < n; i++)
      {
            int minIdx = i;
            for (int j = i + 1; j < n; j++)
            {
                  count3++;
                  if (arr[j] < arr[minIdx])
                  {
                        minIdx = j;
                  }
            }
            if (minIdx != i)
            {
                  int temp = arr[minIdx];
                  arr[minIdx] = arr[i];
                  arr[i] = temp;
            }
      }
}

void printArray(int *arr, int n)
{
      printf("Sorted array: ");
      for (int i = 0; i < n; i++)
      {
            printf("%d ", *(arr + i));
      }
      printf("\n");
}

void tester()
{
      int n;
      printf("Enter the size of the array: ");
      scanf("%d", &n);

      int *arr = (int *)malloc(sizeof(int) * n);

      printf("Enter the elements of the array: ");
      for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);

      selectionSort(arr, n);
      printf("sorted array : ");
      printArray(arr, n);

      free(arr);
}

void plotter()
{
      FILE *f7 = fopen("selection.txt", "a");
      int n = 10;
      int *arr3;

      while (n <= 30000)
      {
            arr3 = (int *)malloc(sizeof(int) * n);
            for (int i = 0; i < n; i++)
                  arr3[i] = i;

            count3 = 0;
            selectionSort(arr3, n);
            fprintf(f7, "%d\t%d\n", n, count3);

            if (n < 10000)
                  n *= 10;
            else
                  n += 10000;

            free(arr3);
      }
      fclose(f7);
      printf("data entered to file.\n");
}

int main()
{

      tester();
      plotter();
      return 0;
}