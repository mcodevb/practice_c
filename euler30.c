#include <stdio.h>
#include <math.h>
int main()
{
    // int n1, n2, gcd, lcm;
    int num, rem, quotient, i, sum = 0, sum_digit;

    for (num = 2; num < 100000; num++)
    {
        quotient = num;
        sum_digit = 0;
        while (quotient !=0 )
        {
            rem = quotient % 10;
            quotient = quotient / 10;
            sum_digit = sum_digit + pow(rem, 4);
        }
        if (num == sum_digit){
            printf("%d\n", num);
            sum=  sum  +  num;
        }
    }
    printf("sum = %d\n",sum);

    return 0;
}