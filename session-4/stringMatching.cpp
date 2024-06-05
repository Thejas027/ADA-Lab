#include <bits/stdc++.h>
using namespace std;

class StringMatching
{
public:
      int match(string &str, string &pattern)
      {
            int count = 0;
            int n = str.size();
            int m = pattern.size();
            for (int i = 0; i <= n - m; i++)
            {
                  int j = 0;
                  while (j < m && str[i + j] == pattern[j])
                  {
                        count++;
                        j++;
                  }
                  if (j == m)
                        return count; // gives the total number of comparision
            }
            return count;
      }
};

class Plotter
{
public:
      void plot()
      {
            srand(time(NULL));
            //   files for best,worst and avg file
            ofstream bestFile("stringMatchingBest.txt", ios::app);
            ofstream avgFile("stringMatchingAvg.txt", ios::app);
            ofstream worstFile("stringMatchingWorst.txt", ios::app);

            int n = 10;
            while (n <= 30000)
            {
                  string text(n, 'A');
                  string pattern;

                  for (int i = 0; i < n; i++)
                        text[i] = 'A' + (i % 26); // this line of code is used to generate a text from a to z

                  // worst case
                  pattern = string(n / 2, 'B'); // this generates a pattern of len of half of text size to compare with text string

                  int count = SM.match(text, pattern);
                  worstFile << n << "\t" << count << "\n";

                  // best case
                  pattern = "A"; // pattern for best case with single comparision 

                  count = SM.match(text, pattern);
                  bestFile << n << "\t" << count << "\n";

                  // avg case
                  for (int i = 0; i < n; i++)
                        text[i] = 'A' + (rand() % 26);  // generates text for avg case 

                  pattern = string(n / 2, 'A' + (rand() % 26));  // based on rand function it gives the pattern and text file 
                  
                  count = SM.match(text, pattern);
                  avgFile << n << "\t" << count << "\n";

                  if (n < 10000)
                        n *= 10;
                  else
                        n += 10000;
            }
      }

private:
      StringMatching SM;
};

class Tester
{
public:
      void test()
      {
            string text, pattern;
            cout << "Enter the text: ";
            cin >> text;
            cout << "Enter the pattern: ";
            cin >> pattern;

            cout << "Text: " << text << "\n";
            cout << "Pattern: " << pattern << "\n";

            int count = SM.match(text, pattern);

            cout << "Number of comparisons: " << count << "\n";
      }

private:
      StringMatching SM;
};

class Application
{
public:
      void run()
      {
            while (true)
            {
                  int key;
                  cout << "Enter your choice \n1. To Test\n2. To Plot\n3. To Exit\n";
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
