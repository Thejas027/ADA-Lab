#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count1, count2, count3;

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

void selectionSort(int *arr, int n)
{
      count3 = 0;

      for (int i = 0; i < n; i++)
      {
            int minIdx = i;
            for (int j = i + 1; j < n; j++)
            {
                  count3++;
                  if (arr[j] < arr[minIdx])
                        minIdx = j;
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
      printf("Enter the size of an array : ");
      scanf("%d", &n);
      int *arr = (int *)malloc(sizeof(int) * n);

      printf("Enter the array elements : ");
      for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);

      printf("sorted array using bubble sort.\n");
      bubbleSort(arr, n);
      printArray(arr, n);

      printf("\n\nsorted array using insertion sort.\n");
      insertionSort(arr, n);
      printArray(arr, n);

      printf("\n\nsorted array using selection sort.\n");
      selectionSort(arr, n);
      printArray(arr, n);
}

void plotter()
{
      int n = 10;
      int *arr1, *arr2, *arr3;
      srand(time(NULL));
      FILE *f1 = fopen("bubbleBest.txt", "a");
      FILE *f2 = fopen("insertionBest.txt", "a");
      FILE *f3 = fopen("bubbleWorst.txt", "a");
      FILE *f4 = fopen("insertionWorst.txt", "a");
      FILE *f5 = fopen("bubbleAvg.txt", "a");
      FILE *f6 = fopen("insertionAvg.txt", "a");
      FILE *f7 = fopen("selection.txt", "a");

      while (n < 30000)
      {
            arr1 = (int *)malloc(sizeof(int) * n);
            arr2 = (int *)malloc(sizeof(int) * n);
            arr3 = (int *)malloc(sizeof(int) * n);

            // Best case
            count1 = 0, count2 = 0, count3 = 0;
            for (int i = 0; i < n; i++)
            {
                  arr1[i] = i + 1;
                  arr2[i] = i + 1;
                  arr3[i] = i;
            }
            bubbleSort(arr1, n);
            insertionSort(arr2, n);
            selectionSort(arr3, n);

            fprintf(f1, "%d\t%d\n", n, count1);
            fprintf(f2, "%d\t%d\n", n, count2);
            fprintf(f7, "%d\t%d\n", n, count3);

            // avg case
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
            free(arr3);
      }

      fclose(f1);
      fclose(f2);
      fclose(f3);
      fclose(f4);
      fclose(f5);
      fclose(f6);
      fclose(f7);
      printf("Data entered to file.\n");
}

int main()
{
      tester();
      plotter();
      return 0;
}

// void plotter2()
// {
//       int n = 10;
//       int *best, *avg, *worst;
//       srand(time(NULL));
//       FILE *f1 = fopen("bubble.txt", "a");
//       FILE *f2 = fopen("insertion.txt", "a");
//       FILE *f3 = fopen("selection.txt", "a");

//       while (n < 30000)
//       {
//             best = (int *)malloc(sizeof(int) * n);
//             avg = (int *)malloc(sizeof(int) * n);
//             worst = (int *)malloc(sizeof(int) * n);

//             // bubble sort
//             count1 = 0, count2 = 0, count3 = 0;

//             for (int i = 0; i < n; i++)
//             {
//                   best[i] = i + 1;
//                   avg[i] = rand() % n;
//                   worst[i] = n - i;
//             }
//             bubbleSort(best, n);
//             bubbleSort(avg, n);
//             bubbleSort(worst, n);

//             fprintf(f1,"%d")
//       }
// }