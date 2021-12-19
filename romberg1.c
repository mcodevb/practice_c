#include <stdio.h>
#include <math.h>
// Romberg Integration
float f(float x)
{
    return 1.0 / (x * x + 1);
}

int main()
{
    int i, j, n;
    float a, b, h, sum, T[10][10];
    printf("enter a, b, n:");
    scanf("%f %f %d", &a, &b, &n);
    h = (b - a);
    T[0][0] = (h / 2.0) * (f(a) + f(b));
    for (i = 1; i < n; i++)
    {
        h = h / 2;
        sum = (1 / 2.0) * T[i - 1][0];
        for (j = 1; j <= pow(2, i); j = j + 2)
        {
            sum = sum + h * f(a + j * h);
        }
        T[i][0] = sum;
    }

    for (j = 1; j < n; j++)
        for (i = j; i < n; i++)
            T[i][j] = (pow(4.0, j) * T[i][j - 1] - T[i - 1][j - 1]) / (pow(4.0, j) - 1.0);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j <= i; j++)
            printf("%f  ", T[i][j]);
        printf("\n");
    }
    return 0;
}
