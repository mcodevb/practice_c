#include <stdio.h>
#include<math.h>
int main(void)
{
    int n, i, j, k, maxiter = 50;

    FILE *inputfile, *outputfile;
    inputfile = fopen("power_input.txt", "r");
    outputfile = fopen("power_output.txt", "w");

    // Input matrix dimension
    fscanf(inputfile, "%d", &n);
    float a[n][n], x[n], xnew[n], lambda_old = 1.0, lambda_new, tol = 1e-5;

    // scan matrix
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            fscanf(inputfile, "%f", &a[i][j]);

    // scan the initial guess vector
    for (i = 0; i < n; i++)
        fscanf(inputfile, "%f", &x[i]);

    // print matrix  on the terminal
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
        printf("   %f\n", x[ii]);
    }

    for (int iter = 1; iter <= maxiter; iter++)
    {
        for (i = 0; i < n; i++)
        {
            float sum = 0.0;
            for (j = 0; j < n; j++)
            {
                sum = sum + a[i][j] * x[j];
            }
            xnew[i] = sum;
        }
        // find maximum element in xnew

        lambda_new = fabs(xnew[0]);
        for (i = 1; i < n; i++)
        {
            if (fabs(xnew[i] > lambda_new))
            {
                lambda_new = fabs(xnew[i]);
            }
        }

        for (i = 0; i < n; i++)
        {
            x[i] = xnew[i] / lambda_new;
        }

        if (fabs(lambda_new - lambda_old) < tol)
        {
            break;
        }
    }

    // print solution in output file
    fprintf(outputfile, "Dominant eigenvalue: %f\n ", lambda_new);

    fclose(inputfile);
    fclose(outputfile);
    return 0;
}
