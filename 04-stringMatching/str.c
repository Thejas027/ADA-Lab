#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>

int count = 0;

int stringMatching(char *text, char *pattern, int n, int m)
{
      count = 0;
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
                  return count;
      }
      return -1;
}

void tester()
{
      char text[100], pattern[100];

      printf("Enter the text : ");
      fgets(text, sizeof(text), stdin);
      text[strcspn(text, "\n")] = '\0';

      printf("Enter the pattern : ");
      fgets(pattern, sizeof(pattern), stdin);
      pattern[strcspn(pattern, "\n")] = '\0';

      int n = strlen(text);
      int m = strlen(pattern);

      int result = stringMatching(text, pattern, n, m);
      if (result == -1)
            printf("pattern did not matched.\n");
      else
      {
            printf("pattern matched.\n");
            printf("Number of comparisons : %d", result);
      }
}

void plotter()
{
      FILE *f1 = fopen("best.txt", "a");
      FILE *f2 = fopen("avg.txt", "a");
      FILE *f3 = fopen("worst.txt", "a");

      int n = 1000;
      char *text = (char *)malloc(sizeof(char) * n);
      char *pattern;

      for (int i = 0; i < n; i++)
            text[i] = 'a';

      int m = 10;

      while (m <= n)
      {
            pattern = (char *)malloc(sizeof(char) * m);

            // best case
            count = 0;
            for (int i = 0; i < m; i++)
                  pattern[i] = 'a';
            stringMatching(text, pattern, n, m);
            fprintf(f1, "%d\t%d\n", m, count);

            // worst case
            count = 0;
            pattern[m - 1] = 'b';
            stringMatching(text, pattern, n, m);
            fprintf(f3, "%d\t%d\n", m, count);

            // avg case
            count = 0;
            for (int i = 0; i < m; i++)
                  pattern[i] = 97 + rand() % 3;
            stringMatching(text, pattern, n, m);
            fprintf(f2, "%d\t%d\n", m, count);

            free(pattern);
            if (m < 100)
                  m += 10;
            else
                  m += 100;
      }
      fclose(f1);
      fclose(f2);
      fclose(f3);
}

int main()
{
      tester();
      plotter();
      printf("\ndata file added.\n");
      return 0;
}