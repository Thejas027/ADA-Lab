#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count;

void bubbleSort(int *arr, int n)
{
      count = 0;
      for (int i = 0; i < n - 1; i++)
      {
            int flag = 0;
            for (int j = i; j < n - i - 1; j++)
            {
                  count++;
                  if (arr[j] > arr[j + 1])
                  {
                        int temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                        flag = 1;
                  }
            }
            if (flag == 0)
                  break;
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

      bubbleSort(arr, n);
      printf("sorted array : ");
      printArray(arr, n);

      free(arr);
}

void plotter()
{
      int n = 10;
      int *arr;
      FILE *f1 = fopen("bubbleBest.txt", "a");
      FILE *f2 = fopen("bubbleAvg.txt", "a");
      FILE *f3 = fopen("bubbleWorst.txt", "a");

      while (n < 30000)
      {
            arr = (int *)malloc(sizeof(int) * n);
            count = 0;
            // best case
            for (int i = 0; i < n; i++)
                  arr[i] = i + 1;
            bubbleSort(arr, n);
            fprintf(f1, "%d\t%d\n", n, count);

            // worst case
            count = 0;
            for (int i = 0; i < n; i++)
                  arr[i] = n - i;
            bubbleSort(arr, n);
            fprintf(f2, "%d\t%d\n", n, count);

            // average case
            count = 0;
            for (int i = 0; i < n; i++)
                  arr[i] = rand() % n;
            bubbleSort(arr, n);
            fprintf(f3, "%d\t%d\n", n, count);

            if (n < 10000)
                  n = n * 10;
            else
                  n = n + 10000;

            free(arr);
      }
      fclose(f1);
      fclose(f2);
      fclose(f3);
      printf("data added to text file.\n");
}

int main()
{
      plotter();
      tester();

      return 0;
}
