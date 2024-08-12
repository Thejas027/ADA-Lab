#include <stdio.h>
#include <stdlib.h>

int count = 0;
int merge(int *arr, int start, int mid, int end)
{
      int n1 = mid - start + 1;
      int n2 = end - mid;
      int left[n1], right[n2];

      for (int i = 0; i < n1; i++)
            left[i] = arr[start + i];

      for (int j = 0; j < n2; j++)
            right[j] = arr[mid + j + 1];

      int i = 0, j = 0, k = start;

      while (i < n1 && j < n2)
      {
            count++;
            if (left[i] <= right[j])
                  arr[k++] = left[i++];
            else
                  arr[k++] = right[j++];
      }

      while (i < n1)
            arr[k++] = left[i++];
      while (i < n2)
            arr[k++] = right[i++];
}

void mergeSort(int *arr, int start, int end)
{
      if (start < end)
      {
            int mid = start + (end - start) / 2;
            mergeSort(arr, start, mid);
            mergeSort(arr, mid + 1, end);
            merge(arr, start, mid, end);
      }
}

void worst(int *arr, int start, int end)
{
      if (start < end)
      {
            int mid = start + (end - start) / 2;
            int n1 = mid - start + 1;
            int n2 = end - mid;
            int a[n1], b[n2];

            for (int i = 0; i < n1; i++)
                  a[i] = arr[i * 2];

            for (int j = 0; j < n2; j++)
                  b[j] = arr[j * 2 + 1];

            worst(a, 0, n1 - 1);
            worst(b, 0, n2 - 1);

            for (int i = 0; i < n1; i++)
                  arr[i] = a[i];

            for (int j = 0; j < n2; j++)
                  arr[j + n1] = b[j];
      }
}

void tester()
{
      int n;
      printf("Enter the size of an array ; ");
      scanf("%d", &n);

      int *arr = (int *)malloc(sizeof(int) * n);

      printf("Enter elements to array : ");
      for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);

      mergeSort(arr, 0, n - 1);

      printf("Array elements after sorting : ");
      for (int i = 0; i < n; i++)
            printf("%d ", arr[i]);

      free(arr);
}

void plotter()
{
      int n, *arr;
      FILE *f1, *f2, *f3, *f4;
      f1 = fopen("mergeBest.txt", "a");
      f2 = fopen("mergeWorst.txt", "a");
      f3 = fopen("mergeAvg.txt", "a");
      f4 = fopen("worstData.txt", "a");

      for (n = 2; n <= 1024; n = n * 2)
      {
            arr = (int *)malloc(sizeof(int) * n);

            // best case
            for (int i = 0; i < n; i++)
                  arr[i] = i + 1;
            count = 0;
            mergeSort(arr, 0, n - 1);
            fprintf(f1, "%d\t%d\n", n, count);

            // worst case
            count = 0;
            worst(arr, 0, n - 1);
            for (int i = 0; i < n; i++)
                  fprintf(f4, "%d ", arr[i]);
            fprintf(f4, "\n");
            mergeSort(arr, 0, n - 1);
            fprintf(f2, "%d\t%d\n", n, count);

            // average case
            for (int i = 0; i < n; i++)
                  arr[i] = rand() % n;
            count = 0;
            mergeSort(arr, 0, n - 1);
            fprintf(f3, "%d\t%d\n", n, count);

            free(arr);
      }
      fclose(f1);
      fclose(f2);
      fclose(f3);
      fclose(f4);
}

int main()
{
      tester();
      plotter();
      printf("\ndata has been added to file.\n");
      return 0;
}