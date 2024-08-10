#include <stdio.h>
#include <stdlib.h>

int count;

int linearSearch(int *arr, int n, int key)
{
      count = 0;
      for (int i = 0; i < n; i++)
      {
            count++;
            if (*(arr + i) == key)
            {
                  printf("Key found at index: %d\n", i);
                  return count;
            }
      }
      printf("Key not found in the array.\n");
      return count;
}

void tester()
{
      int n, key;
      printf("Enter the size of array: ");
      scanf("%d", &n);

      int *arr = (int *)malloc(sizeof(int) * n);

      printf("Enter the elements of the array: ");
      for (int i = 0; i < n; i++)
            scanf("%d", (arr + i));

      printf("Enter the key to be searched: ");
      scanf("%d", &key);

      int comparisons = linearSearch(arr, n, key);
      printf("Number of comparisons: %d\n", comparisons);

      free(arr);
}

void plotter()
{
      FILE *F1, *F2, *F3;
      int *arr;
      int n = 2;

      F1 = fopen("best_case.txt", "w");
      F2 = fopen("average_case.txt", "w");
      F3 = fopen("worst_case.txt", "w");

      if (F1 == NULL || F2 == NULL || F3 == NULL)
      {
            printf("Error opening file(s)!\n");
            return;
      }

      while (n < 1024)
      {
            arr = (int *)malloc(sizeof(int) * n);

            // Best case
            for (int i = 0; i < n; i++)
                  *(arr + i) = 1;
            int data = linearSearch(arr, n, 1);
            fprintf(F1, "%d\t%d\n", n, data);

            // Average case
            for (int i = 0; i < n; i++)
                  *(arr + i) = rand() % n;
            int key = rand() % n;
            data = linearSearch(arr, n, key);
            fprintf(F2, "%d\t%d\n", n, data);

            // Worst case
            for (int i = 0; i < n; i++)
                  *(arr + i) = 0;
            data = linearSearch(arr, n, 1);
            fprintf(F3, "%d\t%d\n", n, data);

            n *= 2;
            free(arr);
      }

      fclose(F1);
      fclose(F2);
      fclose(F3);
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
      {
            tester();
      }
      else if (choice == 2)
      {
            plotter();
      }
      else
      {
            printf("Invalid choice.\n");
      }

      return 0;
}
