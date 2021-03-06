#include <stdio.h>
void main()
{
    int n = 5, i, j;
    float x[5], y[5], diff[5][5], xin, sum, term;
    FILE *fp1, *fp2;
    fp1 = fopen("newton_diff.dat", "r");
    fp2 = fopen("newton_diff.out", "w");

    for (i = 0; i < n; i++)
    {
        fscanf(fp1, "%f", &x[i]);
    }
    for (i = 0; i < n; i++)
    {
        fscanf(fp1, "%f", &y[i]);
    }

    fscanf(fp1, "%f", &xin);

    for (i = 0; i < n; i++)
    {
        diff[i][0] = y[i];
    }

    for (j = 1; j < n; j++)
    {
        for (i = 0; i < n - j; i++)
        {
            diff[i][j] = (diff[i + 1][j - 1] - diff[i][j - 1]) / (x[i + j] - x[i]);
        }
    }

    for (i = 0; i < n; i++)
    {
        fprintf(fp2, " \n");
        fprintf(fp2, "   %12.4f   ", x[i]);
        for (j = 0; j < n - i; j++)
        {
            fprintf(fp2, "   %12.4f   ", diff[i][j]);
        }
    }

    term = 1;
    sum = diff[0][0];
    for (i = 1; i < n; i++)
    {
        term = term * (xin - x[i - 1]);
        sum = sum + term * diff[0][i];
    }

    fprintf(fp2, "\n\n     f(%.4f) =  %12.8f  \n ", xin, sum);

    fclose(fp1);
    fclose(fp2);
}