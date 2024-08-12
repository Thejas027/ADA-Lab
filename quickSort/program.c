#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count;

void swap(int *a, int *b)
{
      int temp = *a;
      *a = *b;
      *b = temp;
}

int partition(int *arr, int start, int end)
{
      int pivot = arr[start];
      int i = start, j = end + 1;

      while (1)
      {
            do
            {
                  count++;
                  i++;
            } while (arr[i] < pivot && i <= end);

            do
            {
                  j--;
                  count++;
            } while (arr[j] > pivot);

            if (i >= j)
                  break;

            swap(&arr[i], &arr[j]);
      }

      swap(&arr[start], &arr[j]);

      return j;
}

void quickSort(int *arr, int start, int end)
{
      if (start < end)
      {
            int mid = partition(arr, start, end);
            quickSort(arr, start, mid - 1);
            quickSort(arr, mid + 1, end);
      }
}

void tester()
{
      int n;
      printf("Enter the size of an array: ");
      scanf("%d", &n);

      int *arr = (int *)malloc(sizeof(int) * n);

      printf("Enter the elements of the array: ");
      for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);

      quickSort(arr, 0, n - 1);

      printf("The array elements after sorting: ");
      for (int i = 0; i < n; i++)
            printf("%d ", arr[i]);
      printf("\n");

      free(arr);
}

void plotter()
{
      int n = 4;
      int *arr;

      FILE *f1, *f2, *f3;
      f1 = fopen("best.txt", "a");
      f2 = fopen("avg.txt", "a");
      f3 = fopen("worst.txt", "a");

      while (n < 1034)
      {
            arr = (int *)malloc(sizeof(int) * n);

            // Best case
            count = 0;
            for (int i = 0; i < n; i++)
                  arr[i] = 5;
            quickSort(arr, 0, n - 1);
            fprintf(f1, "%d\t%d\n", n, count);

            // Worst case
            count = 0;
            for (int i = 0; i < n; i++)
                  arr[i] = i + 1;
            quickSort(arr, 0, n - 1);
            fprintf(f3, "%d\t%d\n", n, count);

            // Average case
            count = 0;
            srand(time(NULL));
            for (int i = 0; i < n; i++)
                  arr[i] = rand() % n;
            quickSort(arr, 0, n - 1);
            fprintf(f2, "%d\t%d\n", n, count);

            free(arr);
            n *= 2;
      }

      fclose(f1);
      fclose(f2);
      fclose(f3);
}

int main()
{
      tester();
      plotter();
      printf("Data added to files.\n");
      return 0;
}
