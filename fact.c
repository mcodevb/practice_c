#include <stdio.h>
#include <math.h>

main()
{
    int n, i, fact;

    printf("Give an interger to calculate its factorial: \n");
    scanf("%d",&n);

    fact=1;
    if (n<0)
    {
       printf("Only non-negative integers are allowed");
    }
    else if (n==0 || n==1)
    {
       printf("%d!=%d",n,fact);
    }
    else
    {
      for ( i = 1; i <= n; i++)
      {
        fact=fact*i;
      }
      printf("%d!=%d",n,fact);
    }

}