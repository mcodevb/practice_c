#include<stdio.h>
#include<math.h>
int isprime(int n);

int main()
{
    int n, m;
    printf("Give an integer to find its factors\n");
    scanf("%d", &n);
    printf("You have entered %d \n",n);

    for ( m = 2; m <= n; m++)
    {
        if (isprime(m)==1)
        {
            if (n%m == 0)
            {
                printf("%d\n",m);
            }

        }
    }
 
    return 0;
}

int isprime(int n)
{
    // 1 for prime, 0 for others
    int i;
    if (n < 2)
        return 0;

    // if (n == 2)
    //     return 1;

    if (n >= 2)
    {
        for (i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
               return 0;
        }
        return 1;
    }
}