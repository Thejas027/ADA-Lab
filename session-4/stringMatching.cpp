#include <bits/stdc++.h>
using namespace std;

class StringMatching
{
public:
      int match(const string &text, const string &pattern)
      {
            int count = 0;
            int n = text.size();
            int m = pattern.size();
            for (int i = 0; i <= n - m; i++)
            {
                  int j = 0;
                  while (j < m)
                  {
                        count++;
                        if (text[i + j] != pattern[j])
                              break;
                        j++;
                  }
                  if (j == m)
                        return count; // Return count when pattern is found
            }
            return count; // Return total count if pattern is not found
      }
};

class Plotter
{
public:
      void plot()
      {
            srand(time(NULL));

            ofstream bestFile("stringMatchingBest.txt", ios::app);
            ofstream avgFile("stringMatchingAvg.txt", ios::app);
            ofstream worstFile("stringMatchingWorst.txt", ios::app);

            string text(1000, 'a');
            int m = 10;
            while (m <= 1000)
            {
                  string pattern;

                  // Best case: pattern is a sequence of 'a's
                  pattern = string(m, 'a');
                  int count = SM.match(text, pattern);
                  bestFile << m << "\t" << count << "\n";

                  // Worst case: last character of pattern is different
                  pattern[m - 1] = 'b';
                  count = SM.match(text, pattern);
                  worstFile << m << "\t" << count << "\n";

                  // Average case: pattern is a random sequence
                  for (int i = 0; i < m; i++)
                        pattern[i] = 'a' + rand() % 3;
                  count = SM.match(text, pattern);
                  avgFile << m << "\t" << count << "\n";

                  if (m < 100)
                        m += 10;
                  else
                        m += 100;
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
