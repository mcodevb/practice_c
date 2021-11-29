#include <stdio.h>
void main()
{
    int n = 5, i, j;
    float x[5], y[5], diff[5][5];
    FILE *fp1, *fp2;
    fp1 = fopen("ndd_input.txt", "r");
    fp2 = fopen("ndd_output.txt", "w");

    for (i = 0; i < n; i++)
    {
        fscanf(fp1, "%f", &x[i]);
    }
    for (i = 0; i < n; i++)
    {
        fscanf(fp1, "%f", &y[i]);
    }

    for (i = 0; i < n; i++)
    {
        diff[i][0] = y[i];
    }

    for (j = 1; j < n; j++)
    {
        for (i = 0; i <= n - j; i++)
        {
            diff[i][j] = (diff[i + 1][j - 1] - diff[i][j - 1]) / (x[i + j] - x[i]);
        }
    }

    for (i = 0; i < n; i++)
    {
        fprintf(fp2, " \n");
        fprintf(fp2, "   %12.4f   ", x[i]);
        for (j = 0; j <= n - i; j++)
        {
            fprintf(fp2, "   %12.4f   ", diff[i][j]);
        }
    }
    fclose(fp1);
    fclose(fp2);
}