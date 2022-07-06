#include <stdio.h>
#include <math.h>
float f(float x)
{
  return exp(-x*x);
}
void main()
{
  FILE *fp1, *fp2;
  float a, b, h, T[20][20], sum;
  int i, j, k, m, n, w;
  fp1 = fopen("romberg.dat", "r");
  fp2 = fopen("romberg.out", "w");
  fscanf(fp1, "%f %f %d", &a, &b, &n);
  h = b - a; // initial step size for Trapezoidal rule
  m = 1;    
  T[0][0] = (h / 2.0) * (f(a) + f(b)); // initial estimate using Trapezoidal rule
  for (i = 1; i < n; i++) // Trapezoidal rule for h/(2^n)
  {
    h = h / 2.0; // when step size is halved
    m = 2 * m;   // number of intervals gets doubled
    sum = 0.5 * T[i - 1][0];
    for (k = 1; k < m; k = k + 2)  //  odd points
    {
      sum = sum + h * f(a + k * h);
    }
    T[i][0] = sum;
  }
  //
  for (j = 1; j < n; j++)
    for (i = j; i < n; i++)
      T[i][j] = (pow(4.0, j) * T[i][j - 1] - T[i - 1][j - 1]) / (pow(4.0, j) - 1.0);

  for (i = 0; i < n; i++)
  {
    for (j = 0; j <= i; j++)
      fprintf(fp2, "%f  ", T[i][j]);
      fprintf(fp2, "\n");
  }
  fprintf(fp2,"\n Romberg estimate of integration =%f\n",T[n-1][n-1]);
  fclose(fp1);
  fclose(fp2);
}
