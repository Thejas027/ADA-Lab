#include <stdio.h>
#include <stdlib.h>

int count;

// Linear Search Function
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

// Recursive Binary Search Function
int binarySearch(int *arr, int low, int high, int key)
{
      if (low <= high)
      {
            count++;
            int mid = low + (high - low) / 2;

            if (*(arr + mid) == key)
            {
                  printf("Key found at index: %d\n", mid);
                  return count;
            }
            else if (*(arr + mid) > key)
                  return binarySearch(arr, low, mid - 1, key);
            else
                  return binarySearch(arr, mid + 1, high, key);
      }
      printf(" key not found.\n");
      return count;
}

// Tester Function
void tester()
{
      int n, key, choice;
      printf("Enter the size of array: ");
      scanf("%d", &n);

      int *arr = (int *)malloc(sizeof(int) * n);

      printf("Enter the elements of the array: ");
      for (int i = 0; i < n; i++)
            scanf("%d", (arr + i));

      printf("Enter the key to be searched: ");
      scanf("%d", &key);

      printf("Select search algorithm:\n");
      printf("1. Linear Search\n");
      printf("2. Binary Search\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);

      switch (choice)
      {
      case 1:
            printf("Linear Search:\n");
            count = linearSearch(arr, n, key);
            printf("Number of comparisons: %d\n", count);
            break;

      case 2:
            // Ensure the array is sorted for binary search
            for (int i = 0; i < n - 1; i++)
            {
                  for (int j = i + 1; j < n; j++)
                  {
                        if (*(arr + i) > *(arr + j))
                        {
                              int temp = *(arr + i);
                              *(arr + i) = *(arr + j);
                              *(arr + j) = temp;
                        }
                  }
            }
            printf("Binary Search:\n");
            count = binarySearch(arr, 0, n - 1, key);
            printf("Number of comparisons: %d\n", count);
            break;

      default:
            printf("Invalid choice.\n");
            break;
      }

      free(arr);
}

void plotter()
{
      FILE *f1, *f2, *f3, *f4, *f5, *f6;
      int *arr;
      int n = 2;

      // Open files for linear search
      f1 = fopen("data1_best.txt", "w");
      f2 = fopen("data1_avg.txt", "w");
      f3 = fopen("data1_worst.txt", "w");

      // Open files for binary search
      f4 = fopen("data2_best.txt", "w");
      f5 = fopen("data2_avg.txt", "w");
      f6 = fopen("data2_worst.txt", "w");

      while (n <= 1024)
      {
            arr = (int *)malloc(n * sizeof(int));

            // Linear Search Cases
            // Best case
            for (int i = 0; i < n; i++)
                  *(arr + i) = 1;

            int data = linearSearch(arr, n, 1);
            fprintf(f1, "%d\t%d\n", n, data);

            // Average case
            for (int i = 0; i < n; i++)
                  *(arr + i) = rand() % n;

            int key = rand() % n;
            data = linearSearch(arr, n, key);
            fprintf(f2, "%d\t%d\n", n, data);

            // Worst case
            for (int i = 0; i < n; i++)
                  *(arr + i) = 0;

            data = linearSearch(arr, n, 1);
            fprintf(f3, "%d\t%d\n", n, data);

            // Binary Search Cases
            // Best-case
            for (int i = 0; i < n; i++)
                  *(arr + i) = i;

            key = (n - 1) / 2;
            count = 0;
            binarySearch(arr, 0, n - 1, key);
            fprintf(f4, "%d\t%d\n", n, count);

            // Worst-case
            for (int i = 0; i < n; i++)
                  *(arr + i) = i;

            key = -1;
            count = 0;
            binarySearch(arr, 0, n - 1, key);
            fprintf(f6, "%d\t%d\n", n, count);

            // Average-case
            for (int i = 0; i < n; i++)
                  *(arr + i) = i;

            key = rand() % n;
            count = 0;
            binarySearch(arr, 0, n - 1, key);
            fprintf(f5, "%d\t%d\n", n, count);

            n *= 2;
            free(arr);
      }

      fclose(f1);
      fclose(f2);
      fclose(f3);
      fclose(f4);
      fclose(f5);
      fclose(f6);
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

