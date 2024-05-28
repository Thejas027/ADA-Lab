#include <bits/stdc++.h>
using namespace std;

class SelectionSort
{
public:
      int sort(vector<int> &arr)
      {
            int count = 0;
            int n = arr.size();
            for (int i = 0; i < n - 1; i++)
            {
                  int min_idx = i;
                  for (int j = i + 1; j < n; j++)
                  {
                        if (arr[j] < arr[min_idx])
                        {
                              min_idx = j;
                              count++;
                        }
                  }
                  if (min_idx != i)
                  {
                        swap(arr[i], arr[min_idx]);
                  }
            }
            return count;
      }
};

class Plotter1
{
public:
      void plotter()
      {
            srand(time(NULL));
      }

      void plot()
      {
            ofstream bestFile("selectionSortBest.txt", ios::app);
            ofstream avgFile("selectionSortAvg.txt", ios::app);
            ofstream WorstFile("selectionSortWorst.txt", ios::app);

            int n = 10;
            while (n <= 30000)
            {
                  vector<int> arr(n);

                  // worst case
                  for (int i = 0; i < n; i++)
                        arr[i] = n - i;
                  int count = SS.sort(arr);
                  WorstFile << n << "\t" << count << "\n";

                  // best case

                  for (int i = 0; i < n; i++)
                        arr[i] = i + 1;
                  count = SS.sort(arr);
                  bestFile << n << "\t" << count << "\n";

                  // avg case
                  for (int i = 0; i < n; i++)
                        arr[i] = rand() % n;
                  count = SS.sort(arr);
                  avgFile << n << "\t" << count << "\n";

                  if (n < 10000)
                        n *= 10;
                  else
                        n += 10000;
            }
      }

private:
      SelectionSort SS;
};

class Tester
{
public:
      void test()
      {
            int n;
            cout << "Enter the number of elements : ";
            cin >> n;

            vector<int> arr(n);

            cout << "Enter the elements to arrray : ";
            for (int i = 0; i < n; i++)
                  cin >> arr[i];

            cout << "Array elements before sorting : ";
            for (auto ele : arr)
                  cout << ele << "";
            cout << "\n";

            SS.sort(arr);

            cout << "Array elements after sorting : ";
            for (auto ele : arr)
                  cout << ele << "";
            cout << "\n";
      }

private:
      SelectionSort SS;
};

class Application
{
public:
      void run()
      {
            while (true)
            {
                  int key;
                  cout << "Enter your choice \n1.To Test\n2.To plot\n3.To Exit\n";
                  cin >> key;

                  switch (key)
                  {
                  case 1:
                        tester.test();
                        break;

                  case 2:
                        plotter.plot();
                        break;

                  case 0:
                        return;

                  default:
                        cout << "INVALID CHOICE. PLEASE TRY AGAIN...";
                        break;
                  }
            }
      }

private:
      Tester tester;
      Plotter1 plotter;
};
int main()

{
      Application app;
      app.run();
      return 0;
}