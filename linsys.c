#include <stdio.h>

int main(void)
{
    int n, i, j, k;

    FILE *inputfile, *outputfile;
    inputfile = fopen("linsys_input.txt", "r");
    outputfile = fopen("linsys_output.txt", "w");

    // Input matrix dimension
    fscanf(inputfile, "%d", &n);
    float a[n][n], b[n], x[n], multiplier;

    // scan the coefficient matrix
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            fscanf(inputfile, "%f", &a[i][j]);

    // scan the rhs values
    for (i = 0; i < n; i++)
        fscanf(inputfile, "%f", &b[i]);

    // print system  on the terminal
    for (int ii = 0; ii < n; ii++)
    {
        for (int jj = 0; jj < n; jj++)
        {
            printf("%f ", a[ii][jj]);
        }
        printf("\n");
    }

    printf("\n b = \n");
    for (int ii = 0; ii < n; ii++)
    {
        printf("   %f\n", b[ii]);
    }

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            multiplier = (a[j][i] / a[i][i]);
            printf("multiplier = %f\n", multiplier);
            for (k = i; k < n; k++)
            {
                a[j][k] = a[j][k] - multiplier * a[i][k];
            }
            b[j] = b[j] - multiplier * b[i];
        }
    }

    // Solve using backward substitution
    for (i = n - 1; i >= 0; i--)
    {
        float sum = 0.0;
        for (j = i + 1; j < n; j++)
        {
            sum += a[i][j] * x[j];
        }
        x[i] = (1.0 / a[i][i]) * (b[i] - sum);
    }

    // print solution in output file
    fprintf(outputfile, "Solution of the given problem is: \n");
    for (i = 0; i < n; i++)
    {
        fprintf(outputfile, "   x(%d) = %f\n", i + 1, x[i]);
    }

    fclose(inputfile);
    fclose(outputfile);
    return 0;
}
