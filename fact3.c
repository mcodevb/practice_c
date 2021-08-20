 int nn, n, i, fact;
    printf("Give an interger to calculate factorial of numbers upto that number: \n");
    scanf("%d",&nn);
    for ( n = 1; n <= nn; n++)
    {
    fact=1;

    if (n<0)
    {
       printf("Only non-negative integers are allowed\n");
    }
    else if (n==0 || n==1)
    {
       printf("%d!=%d\n",n,fact);
    }
    else
    {
      for ( i = 1; i <= n; i++)
      {
        fact=fact*i;
      }
      printf("%d!=%d\n",n,fact);
    }
    }
}