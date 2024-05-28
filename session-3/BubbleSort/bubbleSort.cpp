#include <bits/stdc++.h>
using namespace std;

class BubbleSort
{

public:
      int sort(vector<int> &arr)
      {
            int count = 0;
            bool flag = false;
            int n = arr.size();
            for (int i = 0; i < n - 1; i++)
            {
                  flag = false;
                  for (int j = 0; j < n - i - 2; i++)
                  {
                        ++count;
                        if (arr[j] > arr[j + 1])
                        {
                              swap(arr[j], arr[j + 1]);
                              flag = true;
                        }
                  }
                  if (!flag)
                        break;
            }
            return count;
      }
};

class SelectionSort
{
public:
      int sort(vector<int> &arr)
      {
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
            ofstream bestFile("bubbleSortBest.txt", ios::app);
            ofstream avgFile("bubbleSortAvg.txt", ios::app);
            ofstream WorstFile("bubbleSortWorst.txt", ios::app);

            int n = 10;
            while (n <= 30000)
            {
                  vector<int> arr(n);

                  // worst case
                  for (int i = 0; i < n; i++)
                        arr[i] = n - i;
                  int count = BS.sort(arr);
                  WorstFile << n << "\t" << count << "\n";

                  // best case

                  for (int i = 0; i < n; i++)
                        arr[i] = i + 1;
                  count = BS.sort(arr);
                  bestFile << n << "\t" << count << "\n";

                  // avg case
                  for (int i = 0; i < n; i++)
                        arr[i] = rand() % n;
                  count = BS.sort(arr);
                  avgFile << n << "\t" << count << "\n";

                  if (n < 10000)
                        n *= 10;
                  else
                        n += 10000;
            }
      }

private:
      BubbleSort BS;
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

            BS.sort(arr);

            cout << "Array elements after sorting : ";
            for (auto ele : arr)
                  cout << ele << "";
            cout << "\n";
      }

private:
      BubbleSort BS;
};

class Application
{
public:
      void run()
      {
            while (true)
            {
                  int key;
                  cout << "Enter your choice \n1.To Test\n2.To plot\n3.To Exit";
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