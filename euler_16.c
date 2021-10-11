#include <stdio.h>
#include <math.h>
int main()
{
    double n, r, sum=0.0;
    n = pow(2,100);
    printf("%lf\n", n);
    while (n > 0)
    {
      r = n-floor(n/10.0)*10;
      printf("rem = %lf\n", r);
      sum = r + sum;
      printf("sum = %lf\n", sum);      
      n = floor(n / 10.0);
      printf("n = %lf\n", n);

    }
    printf("%lf", sum);

    return 0;
}