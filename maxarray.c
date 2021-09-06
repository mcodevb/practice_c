#include <stdio.h>
int main()
{
    int n, i;
    printf("enter the value: ");
    scanf("%d", &n);
    int num[n], max;
    printf("input %d numbers: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
    }
    max = num[0];
    for (i = 1; i < n; i++)
    {
        if (max < num[i])
            max = num[i];
    }
    printf("max = %d\n", max);
}