#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count1, count2;

void bubbleSort(int *arr, int n)
{
      count1 = 0;
      for (int i = 0; i < n - 1; i++)
      {
            int flag = 0;
            for (int j = 0; j < n - i - 1; j++)
            {
                  count1++;
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

void insertionSort(int *arr, int n)
{
      count2 = 0;
      for (int i = 1; i < n; i++)
      {
            int value = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > value)
            {
                  arr[j + 1] = arr[j];
                  j--;
                  count2++;
            }
            arr[j + 1] = value;
            count2++;
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
      printf("Enter the size of an array : ");
      scanf("%d", &n);
      int *arr = (int *)malloc(sizeof(int) * n);

      printf("Enter the array elements : ");
      for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);

      int choice;
      printf("Enter\n1.Bubble sort\n2.Insertion sort\n");
      scanf("%d", &choice);

      switch (choice)
      {
      case 1:
            printf("sorted array using bubble sort.\n");
            bubbleSort(arr, n);
            printArray(arr, n);
            break;
      case 2:
            printf("sorted array using insertion sort.\n");
            insertionSort(arr, n);
            printArray(arr, n);
            break;
      default:
            printf("invalid choice.\n");
            break;
      }
}

void plotter()
{
      int n = 10;
      int *arr1, *arr2;
      srand(time(NULL));
      FILE *f1 = fopen("bubbleBest.txt", "a");
      FILE *f2 = fopen("insertionBest.txt", "a");
      FILE *f3 = fopen("bubbleWorst.txt", "a");
      FILE *f4 = fopen("insertionWorst.txt", "a");
      FILE *f5 = fopen("bubbleAvg.txt", "a");
      FILE *f6 = fopen("insertionAvg.txt", "a");

      if (!f1 || !f2 || !f3 || !f4 || !f5 || !f6) // Check if files were opened successfully
      {
            printf("Error opening files!\n");
            return;
      }

      while (n < 30000)
      {
            arr1 = (int *)malloc(sizeof(int) * n);
            arr2 = (int *)malloc(sizeof(int) * n);

            if (!arr1 || !arr2)
            {
                  printf("Memory allocation failed!\n");
                  return;
            }

            // Best case
            count1 = 0;
            count2 = 0;
            for (int i = 0; i < n; i++)
            {
                  arr1[i] = i + 1;
                  arr2[i] = i + 1;
            }
            bubbleSort(arr1, n);
            insertionSort(arr2, n);

            fprintf(f1, "%d\t%d\n", n, count1);
            fprintf(f2, "%d\t%d\n", n, count2);

            // avg case
            count1 = 0;
            count2 = 0;
            for (int i = 0; i < n; i++)
            {
                  arr1[i] = rand() % n;
                  arr2[i] = rand() % n;
            }
            bubbleSort(arr1, n);
            insertionSort(arr2, n);
            fprintf(f5, "%d\t%d\n", n, count1);
            fprintf(f6, "%d\t%d\n", n, count2);

            // Worst case
            for (int i = 0; i < n; i++)
            {
                  arr1[i] = n - i;
                  arr2[i] = n - i;
            }
            bubbleSort(arr1, n);
            insertionSort(arr2, n);
            fprintf(f3, "%d\t%d\n", n, count1);
            fprintf(f4, "%d\t%d\n", n, count2);

            if (n < 10000)
                  n = n * 10;
            else
                  n = n + 10000;

            free(arr1);
            free(arr2);
      }

      fclose(f1);
      fclose(f2);
      fclose(f3);
      fclose(f4);
      fclose(f5);
      fclose(f6);
      printf("Data entered to file.\n");
}

int main()
{
      int choice;
      printf("Enter\n1. To test\n2.To plot\n");
      scanf("%d", &choice);

      switch (choice)
      {
      case 1:
            tester();
            break;

      case 2:
            plotter();
            break;

      default:
            printf("Invalid choice.\n");
            break;
      }
      return 0;
}
