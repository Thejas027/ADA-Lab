#include <stdio.h>
#include <stdlib.h>

int count = 0;

int euclid(int m, int n)
{

      count = 0;
      while (n)
      {
            count++;
            int r = m % n;
            m = n;
            n = r;
      }
      return count;
}

int consecutive(int m, int n)
{
      count = 0;
      int min = m < n ? m : n;
      while (1)
      {
            if (m % min == 0)
            {
                  count++;
                  if (n % min == 0)
                        return count;
            }
            min--;
      }
}

int modified(int m, int n)
{
      count = 1;
      while (m != n)
      {
            (m > n) ? (m = m - n) : (n = n - m);
            count++;
      }
      return count;
}
void tester()
{
      int m, n;
      printf("Enter the value of m and n: ");
      scanf("%d %d", &m, &n);

      printf("GCD using Euclid's method: ");
      printf("%d\n", euclid(m, n));
      printf("Number of operations: %d\n", count);

      printf("GCD using Consecutive Integer method: ");
      printf("%d\n", consecutive(m, n));
      printf("Number of operations: %d\n", count);

      printf("GCD using Modified Euclid's method: ");
      printf("%d\n", modified(m, n));
      printf("Number of operations: %d\n", count);
}

void plotter()
{
      int ch;
      FILE *f1, *f2;
      printf("1. Euclid\n2. Consecutive Integer\n3. Modified\n");
      printf("Enter your choice: ");
      scanf("%d", &ch);

      int maxcount = 0, mincount = 10000;

      for (int i = 10; i <= 100; i += 10)
      {
            for (int j = 2; j <= i; j++)
            {
                  for (int k = 2; k <= i; k++)
                  {
                        count = 0;
                        // int m = j, n = k;
                        switch (ch)
                        {
                        case 1:
                              count = euclid(j, k);
                              break;
                        case 2:
                              count = consecutive(j, k);
                              break;
                        case 3:
                              count = modified(j, k);
                              break;
                        }
                        if (count > maxcount)
                              maxcount = count;
                        if (count < mincount)
                              mincount = count;
                  }
            }
            switch (ch)
            {
            case 1:
                  f1 = fopen("e_best.txt", "a");
                  f2 = fopen("e_worst.txt", "a");
                  break;
            case 2:
                  f1 = fopen("C_best.txt", "a");
                  f2 = fopen("C_worst.txt", "a");
                  break;
            case 3:
                  f1 = fopen("m_best.txt", "a");
                  f2 = fopen("m_worst.txt", "a");
                  break;
            }
            fprintf(f1, "%d\t%d\n", i, mincount);
            fprintf(f2, "%d\t%d\n", i, maxcount);
            fclose(f1);
            fclose(f2);
      }
}

int main()
{
      int ch;
      do
      {
            printf("1. Tester\n2. Plotter\n3. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &ch);
            switch (ch)
            {
            case 1:
                  tester();
                  break;
            case 2:
                  plotter();
                  break;
            case 3:
                  break;
            }
      } while (ch != 3);
      return 0;
}