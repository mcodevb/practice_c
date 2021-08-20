#include <stdio.h>
#include <math.h>

main()
{
    int  n, i, fact=1;
    printf("Give an interger to calculate factorial of numbers upto that number: \n");
    scanf("%d",&n);
      
      for ( i = 1; i <= n; i++)
      {
        fact=fact*i;
        printf("%d!=%d\n",i,fact);
      }
      
}