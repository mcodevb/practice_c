#include <stdio.h>
#include <math.h>

int ispalindrome(int n);

int main()
{
    int p, q, maxx = 0, maxp, maxq;
    for (p = 999; p > 900; p--)
    {
        for (q = 999; q > 900; q--)
        {
            if ((ispalindrome(p * q) == 1) && (p * q > maxx))
            {
                    maxp = p;
                    maxq = q;
                    maxx = p * q;
            }
        }
    }
    printf("\nmaximum palindrome %d*%d = %d\n",maxp, maxq, maxx);
    return 0;
}

int ispalindrome(int num)
{
    // 1 for palindrome numbers and 0 for others
    int temp = num, revnum = 0, remainder;
    while (temp != 0)
    {
        remainder = temp % 10;
        revnum = 10 * revnum + remainder;
        temp = temp / 10;
    }
    if (revnum == num)
        return 1;
    else
        return 0;
}