#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *a, int *b)
{
      int temp = *a;
      *a = *b;
      *b = temp;
}

int count = 0;
int createCount, deleteCount;

void heapify(int *heap, int n, int root)
{
      int largest = root;
      int left = 2 * root + 1;
      int right = 2 * root + 2;

      if (left < n)
      {
            count++;
            if (heap[left] > heap[largest])
                  largest = left;
      }

      if (right < n)
      {
            count++;
            if (heap[right] > heap[largest])
                  largest = right;
      }
      if (largest != root)
      {
            swap(&heap[root], &heap[largest]);
            heapify(heap, n, largest);
      }
}

int heapSort(int *heap, int n)
{
      count = 0;

      for (int i = (n / 2) - 1; i >= 0; i--)
            heapify(heap, n, i);
      createCount = count;

      count = 0;
      for (int i = n - 1; i > 0; i--)
      {
            swap(&heap[0], &heap[i]);
            heapify(heap, i, 0);
      }
      deleteCount = count;

      return createCount > deleteCount ? createCount : deleteCount;
}

void tester()
{
      int n;
      printf("Enter the size of an array : ");
      scanf("%d", &n);

      int arr[n];

      printf("Enter the array elements : ");
      for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);

      heapSort(arr, n);

      printf("Elements after sorting : ");
      for (int i = 0; i < n; i++)
            printf("%d ", arr[i]);
}

void plotter()
{
      FILE *fp = fopen("heap.txt", "a");

      for (int n = 100; n <= 1000; n += 100)
      {
            int *arr = (int *)malloc(sizeof(int) * (n + 1));

            for (int i = 0; i < n; i++)
                  arr[i] = n - i + 1;
            int best = heapSort(arr, n);

            for (int i = 0; i < n; i++)
                  arr[i] = i + 1;
            int worst = heapSort(arr, n);

            for (int i = 0; i < n; i++)
                  arr[i] = rand() % n;
            int avg = heapSort(arr, n);

            fprintf(fp, "%d\t%d\t%d\t%d\n", n, best, avg, worst);
      }
      fclose(fp);
}

int main()
{
      // tester();
      plotter();
      printf("data generated\n");
      return 0;
}