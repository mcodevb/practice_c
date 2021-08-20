#include <stdio.h>
#include <math.h>

void main()
{
    int n, fact;

    printf("Give an interger to calculate its factorial: \n");
    scanf("%d",&n);

    fact=1;
    while (n<0)
    {
       printf("Only non-negative integers are allowed\n");
       printf("Give a non-negative interger: \n");
       scanf("%d",&n);
    }

    if (n==0 || n==1)
    {
       printf("%d!=%d",n,fact);
    }
    else
    {
      int i;
      for ( i = 2; i <= n; i++)
      {
        fact=fact*i;
      }
      printf("%d!=%d",n,fact);
    }

}