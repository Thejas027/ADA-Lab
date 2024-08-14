#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
}

int main()
{
      tester();
      return 0;
}