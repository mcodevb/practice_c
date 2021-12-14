#include <stdio.h>

float f(float x)
{
    return 1.0 / (x * x + 1);
}

void main()
{
    int n, i, j;
    float a, b, sum, h, int_val;
    FILE *fp1, *fp2;
    fp1 = fopen("trapezoidal_input.txt", "r");
    fp2 = fopen("trapezoidal_output.txt", "w");

    fscanf(fp1, "%f %f %d", &a, &b, &n);
    h = (b - a) / n;
    sum = f(a) + f(b);
    for (i = 1; i < n; i++)
    {
        sum = sum + 2 * f(a + i * h);
    }
    int_val = (h / 2.0) * sum;
    fprintf(fp2, "\n\n Value of integration  =  %12.8f  \n ", int_val);

    fclose(fp1);
    fclose(fp2);
}