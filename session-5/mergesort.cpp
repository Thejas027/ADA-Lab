#include <bits/stdc++.h>
using namespace std;

class MergeSort
{
public:
      int count;

      void merge(vector<int> &arr, int beg, int mid, int end)
      {
            int i, j, k;
            int n1 = mid - beg + 1;
            int n2 = end - mid;
            vector<int> left(n1), right(n2);
            for (i = 0; i < n1; i++)
                  left[i] = arr[beg + i];
            for (j = 0; j < n2; j++)
                  right[j] = arr[mid + 1 + j];
            i = 0;
            j = 0;
            k = beg;
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
            while (j < n2)
                  arr[k++] = right[j++];
      }

      void mergeSort(vector<int> &arr, int beg, int end)
      {
            if (beg < end)
            {
                  int mid = beg + (end - beg) / 2;
                  mergeSort(arr, beg, mid);
                  mergeSort(arr, mid + 1, end);
                  merge(arr, beg, mid, end);
            }
      }

      void generateWorstCase(vector<int> &arr, int beg, int end)
      {
            if (beg < end)
            {
                  int mid = beg + (end - beg) / 2;
                  int i, j;
                  int n1 = mid - beg + 1;
                  int n2 = end - mid;
                  vector<int> a(n1), b(n2);
                  for (i = 0; i < n1; i++)
                        a[i] = arr[2 * i];
                  for (j = 0; j < n2; j++)
                        b[j] = arr[2 * j + 1];
                  generateWorstCase(a, beg, mid);
                  generateWorstCase(b, mid + 1, end);
                  for (i = 0; i < n1; i++)
                        arr[i] = a[i];
                  for (j = 0; j < n2; j++)
                        arr[j + i] = b[j];
            }
      }
};

class Plotter
{
public:
      void plot()
      {
            srand(time(NULL));
            ofstream bestFile("MERGESORTBEST.txt", ios::app);
            ofstream worstFile("MERGESORTWORST.txt", ios::app);
            ofstream avgFile("MERGESORTAVG.txt", ios::app);
            ofstream worstDataFile("WORSTDATA.txt", ios::app);

            for (int n = 2; n <= 1024; n *= 2)
            {
                  vector<int> arr(n);
                  iota(arr.begin(), arr.end(), 1); // Fill array with 1, 2, ..., n
                  MS.count = 0;

                  // Best case
                  MS.mergeSort(arr, 0, n - 1);
                  bestFile << n << "\t" << MS.count << "\n";

                  // Worst case
                  MS.generateWorstCase(arr, 0, n - 1);
                  for (int i = 0; i < n; i++)
                        worstDataFile << arr[i] << " ";
                  worstDataFile << "\n";
                  MS.count = 0;
                  MS.mergeSort(arr, 0, n - 1);
                  worstFile << n << "\t" << MS.count << "\n";

                  // Average case
                  for (int i = 0; i < n; i++)
                        arr[i] = rand() % n;
                  MS.count = 0;
                  MS.mergeSort(arr, 0, n - 1);
                  avgFile << n << "\t" << MS.count << "\n";
            }

            bestFile.close();
            worstFile.close();
            avgFile.close();
            worstDataFile.close();

            cout << "DATA IS ENTERED INTO FILE\n";
      }

private:
      MergeSort MS;
};

class Tester
{
public:
      void test()
      {
            int n;
            cout << "Enter the number of elements: ";
            cin >> n;

            vector<int> arr(n);
            cout << "Enter the elements of the array: ";
            for (int i = 0; i < n; i++)
                  cin >> arr[i];

            cout << "Array elements before sorting: ";
            for (auto ele : arr)
                  cout << ele << " ";
            cout << "\n";

            MS.mergeSort(arr, 0, n - 1);

            cout << "Array elements after sorting: ";
            for (auto ele : arr)
                  cout << ele << " ";
            cout << "\n";
      }

private:
      MergeSort MS;
};

class Application
{
public:
      void run()
      {
            while (true)
            {
                  int key;
                  cout << "Enter your choice:\n1. To Test\n2. To Plot\n3. To Exit\n";
                  cin >> key;

                  switch (key)
                  {
                  case 1:
                        tester.test();
                        break;

                  case 2:
                        plotter.plot();
                        break;

                  case 3:
                        return;

                  default:
                        cout << "INVALID CHOICE. PLEASE TRY AGAIN...\n";
                        break;
                  }
            }
      }

private:
      Tester tester;
      Plotter plotter;
};

int main()
{
      Application app;
      app.run();
      return 0;
}
