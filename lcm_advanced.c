#include <stdio.h>
int lcm(int p, int q);
int main()
{
    int p, q, lcmm;
    printf("Enter lower limit: ");
    scanf("%d",&p);
    printf("Enter upper limit: ");
    scanf("%d",&q);
    lcmm = lcm(p,q);
    printf("%d\n",lcmm);
    return 0;
}

int lcm(int p, int q)
{
    int n1 = p, n2 = q;
    while (p != q)
    {
        if (p > q)
            p -= q;
        else
            q -= p;
    }


    return n1 * (n2 / p);
}