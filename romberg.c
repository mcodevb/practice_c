#include <stdio.h>
#include <math.h>
float f(float x)
{
  return 1.0 / (x * x + 1);
}
void main()
{
  FILE *fp1, *fp2;
  float a, b, h, T[10][10], sum;
  int i, j, k, m, n, w;
  fp1 = fopen("romberg_input.txt", "r");
  fp2 = fopen("romberg_output.txt", "w");
  fscanf(fp1, "%f %f %d", &a, &b, &n);
  h = b - a;
  m = 1;
  T[0][0] = (h / 2.0) * (f(a) + f(b));
  for (i = 1; i < n; i++)
  {
    h = h / 2.0;
    m = 2 * m;
    sum = 0.5 * T[i - 1][0];
    for (k = 1; k < m; k = k + 2)
    {
      sum = sum + h * f(a + k * h);
    }
    T[i][0] = sum;
  }

  for (j = 1; j < n; j++)
    for (i = j; i < n; i++)
      T[i][j] = (pow(4.0, j) * T[i][j - 1] - T[i - 1][j - 1]) / (pow(4.0, j) - 1.0);

  for (i = 0; i < n; i++)
  {
    for (j = 0; j <= i; j++)
      fprintf(fp2, "%f  ", T[i][j]);
    fprintf(fp2, "\n");
  }

  fclose(fp1);
  fclose(fp2);
}
