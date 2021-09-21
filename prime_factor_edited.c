
#include <stdio.h>
#include <math.h>

int isprime(int n);

int main()
{
    long int n = 2;
    long int n1;

    printf("enter the value of n1\n");
    scanf("%ld", &n1);
    printf("Entered Value: %ld", n1);
    long int max = 0;
    while (n1 > 1)
    {
        if (n1 % n == 0)
        {
            printf("\n %ld", n);
            max = n;
            while (n1 % n == 0)
            {
                n1 /= n;
            }
        }
        n = n + 1;
    }
    printf("\n"); // just adding a linebreak
    printf("max = %ld\n", max);
    return 0;
}
