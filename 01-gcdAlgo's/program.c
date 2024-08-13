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
      return m;
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
                        return min;
            }
            min--;
            count++;
      }
      return m;
}

int modified(int m, int n)
{
      count = 1;
      while (m != n)
      {
            if (m > n)
                  m = m - n;
            else
                  n = n - m;
            count++;
      }
      return m;
}

void tester()
{
      int m, n;
      printf("Enter the value of m and n: ");
      scanf("%d %d", &m, &n);

      printf("GCD using Euclid's method: %d\n", euclid(m, n));
      printf("Number of operations: %d\n", count);

      printf("GCD using Consecutive Integer method: %d\n", consecutive(m, n));
      printf("Number of operations: %d\n", count);

      printf("GCD using Modified Euclid's method: %d\n", modified(m, n));
      printf("Number of operations: %d\n", count);
}

void plotter()
{
      FILE *f1 = fopen("e_best.txt", "a");
      FILE *f2 = fopen("e_worst.txt", "a");
      FILE *f3 = fopen("c_best.txt", "a");
      FILE *f4 = fopen("c_worst.txt", "a");
      FILE *f5 = fopen("m_best.txt", "a");
      FILE *f6 = fopen("m_worst.txt", "a");

      for (int i = 10; i <= 100; i += 10)
      {
            int e_min = 10000, e_max = 0;
            int c_min = 10000, c_max = 0;
            int m_min = 10000, m_max = 0;

            for (int j = 2; j <= i; j++)
            {
                  for (int k = 2; k <= i; k++)
                  {

                        // Euclid's method
                        count = euclid(j, k);
                        if (count > e_max)
                              e_max = count;
                        if (count < e_min)
                              e_min = count;

                        // Consecutive integer method
                        count = consecutive(j, k);
                        if (count > c_max)
                              c_max = count;
                        if (count < c_min)
                              c_min = count;

                        // Modified Euclid's method
                        count = modified(j, k);
                        if (count > m_max)
                              m_max = count;
                        if (count < m_min)
                              m_min = count;
                  }
            }

            fprintf(f1, "%d\t%d\n", i, e_min);
            fprintf(f2, "%d\t%d\n", i, e_max);
            fprintf(f3, "%d\t%d\n", i, c_min);
            fprintf(f4, "%d\t%d\n", i, c_max);
            fprintf(f5, "%d\t%d\n", i, m_min);
            fprintf(f6, "%d\t%d\n", i, m_max);
      }

      fclose(f1);
      fclose(f2);
      fclose(f3);
      fclose(f4);
      fclose(f5);
      fclose(f6);
}

int main()
{
      plotter();
      tester();
      return 0;
}