#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

// #include <bits/stdc++.h>

using namespace std;
class InsertionSort
{

public:
      int sort(vector<int> &arr)
      {
            int count = 0;
            int n = arr.size();
            for (int i = 1; i < n; i++)
            {
                  int value = arr[i];
                  int j = i - 1;
                  while (j >= 0 && arr[j] > value)
                  {
                        arr[j + 1] = arr[j];
                        j--;
                        count++;
                  }
                  arr[j + 1] = value;
                  count++;
            }
            return count;
      }
};

class Plotter
{

public:
      void plotter()
      {
            srand(time(NULL));
      }

      void plot()
      {
            ofstream bestCase("insertionBest.txt", ios::app);
            ofstream avgCase("insertionAvg.txt", ios::app);
            ofstream worstCase("insertionWorst.txt", ios::app);

            int n = 10;

            while (n < 30000)
            {
                  vector<int> arr(n);

                  // worst case
                  for (int i = 0; i < n; i++)
                        arr[i] = n - i;
                  int count = IS.sort(arr);
                  worstCase << n << "\t" << count << "\n";

                  // best case
                  for (int i = 0; i < n; i++)
                        arr[i] = i + 1;
                  count = IS.sort(arr);
                  bestCase << n << "\t" << count << "\n";

                  // avg case
                  for (int i = 0; i < n; i++)
                        arr[i] = rand() % n;
                  count = IS.sort(arr);
                  avgCase << n << "\t" << count << "\n";

                  if (n < 30000)
                        n *= 10;
                  else
                        n += 100000;
            }
      }

private:
      InsertionSort IS;
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
                  cout << ele << " ";
            cout << "\n";

            IS.sort(arr);

            cout << "Array elements after sorting : ";
            for (auto ele : arr)
                  cout << ele << " ";
            cout << "\n";
      }

private:
      InsertionSort IS;
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
      Plotter plotter;
};
int main()

{
      Application app;
      app.run();
      return 0;
}