#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count2;

void insertionSort(int *arr, int n)
{
      count2 = 0;

      for (int i = 1; i < n; i++)
      {
            int key = arr[i];
            int j = i - 1;

            while (j >= 0 && arr[j] > key)
            {
                  arr[j + 1] = arr[j];
                  j--;
                  count2++;
            }
            arr[j + 1] = key;
            count2++;
      }
}

void tester()
{
      int n;
      printf("Enter the array size: ");
      scanf("%d", &n);

      int *arr = (int *)malloc(sizeof(int) * n);
      if (!arr)
      {
            printf("Memory allocation failed!\n");
            return;
      }

      printf("Enter the elements to array: ");
      for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);

      printf("Array elements after sorting: ");
      insertionSort(arr, n);

      for (int i = 0; i < n; i++)
            printf("%d ", arr[i]);
      printf("\n");

      free(arr);
}

void plotter()
{
      int n = 10;
      int *arr;
      srand(time(NULL));
      FILE *F4 = fopen("insertionBest.txt", "a");
      FILE *F5 = fopen("insertionAvg.txt", "a");
      FILE *F6 = fopen("insertionWorst.txt", "a");

      while (n < 30000)
      {
            arr = (int *)malloc(sizeof(int) * n);
            count2 = 0;
            // best case
            for (int i = 0; i < n; i++)
                  arr[i] = i + 1;
            insertionSort(arr, n);
            fprintf(F4, "%d\t%d\n", n, count2);

            // avg case
            count2 = 0;
            for (int i = 0; i < n; i++)
                  arr[i] = rand() % n;
            insertionSort(arr, n);
            fprintf(F5, "%d\t%d\n", n, count2);

            // worst case
            count2 = 0;
            for (int i = 0; i < n; i++)
                  arr[i] = n - i;
            insertionSort(arr, n);
            fprintf(F6, "%d\t%d\n", n, count2);

            if (n < 10000)
                  n = n * 10;
            else
                  n = n + 10000;
            free(arr);
      }
      fclose(F5);
      fclose(F4);
      fclose(F6);
}

int main()
{
      int choice;
      printf("Select an option:\n");
      printf("1. Run Tester\n");
      printf("2. Run Plotter\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);

      if (choice == 1)
            tester();
      else if (choice == 2)
            plotter();
      else
            printf("Invalid choice.\n");

      return 0;
}