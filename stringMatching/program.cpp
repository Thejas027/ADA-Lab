#include <bits/stdc++.h>
using namespace std;

int stringMatching(string &text, string &pattern)
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
                  if (pattern[j] != text[i + j])
                        break;
                  j++;
            }
            if (j == m)
                  count++;
      }
      return count;
}

void tester()
{
      string text, pattern;

      cout << "Enter the text: ";
      getline(cin, text);
      cout << "Enter the pattern: ";
      getline(cin, pattern);

      // Printing of text and pattern
      cout << "TEXT: " << text << endl;
      cout << "PATTERN: " << pattern << endl;

      int count = stringMatching(text, pattern);
      cout << "Number of comparisons: " << count << "\n";
}

void plotter()
{
      srand(time(NULL));
      ofstream best("strBest.txt", ios::app);
      ofstream avg("strAvg.txt", ios::app);
      ofstream worst("strWorst.txt", ios::app);

      string text(1000, 'a');
      int n = 10;

      while (n <= 1000)
      {
            string pattern;

            // best case
            pattern = string(n, 'a');
            int count = stringMatching(text, pattern);
            best << n << "\t" << count << "\n";

            // avg case
            for (int i = 0; i < n; i++)
                  pattern[i] = 'a' + rand() % 3;
            count = stringMatching(text, pattern);
            avg << n << "\t" << count << "\n";

            // worst case
            pattern[n - 1] = 'b';
            count = stringMatching(text, pattern);
            worst << n << "\t" << count << "\n";

            if (n < 100)
                  n += 10;
            else
                  n += 100;
      }
}

int main()
{
      tester();
      plotter();
      return 0;
}
