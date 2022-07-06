#include <stdio.h>
#include<math.h>
int main(void)
{
    int n, i, j, k, maxiter;

    FILE *fp1, *fp2;
    fp1 = fopen("power.dat", "r");
    fp2 = fopen("power.out", "w");

    // Input matrix dimension
    fscanf(fp1, "%d %d", &n, &maxiter);
    float a[n][n], x[n], xnew[n], lambda_old = 1.0, lambda_new, tol = 1e-7; // 6 decimal place: 0.5e-6

    // scan matrix
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            fscanf(fp1, "%f", &a[i][j]);

    // scan the initial guess vector
    for (i = 0; i < n; i++)
        fscanf(fp1, "%f", &x[i]);

    // print matrix  on the terminal
    fprintf(fp2, "\n Given Matrix A = \n\t");
    for (int ii = 0; ii < n; ii++)
    {
        for (int jj = 0; jj < n; jj++)
        {
            fprintf(fp2,"%f ", a[ii][jj]);
        }
        fprintf(fp2,"\n\t");
    }

    fprintf(fp2, "\ninitial guess vector = \n");
    for (int ii = 0; ii < n; ii++)
    {
        fprintf(fp2, "%f\n", x[ii]);
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

        // find maximum (in magnitude) element in xnew
        lambda_new = fabs(xnew[0]);
        for (i = 1; i < n; i++)
        {
            if (fabs(xnew[i]) > lambda_new)
            {
                lambda_new = fabs(xnew[i]);
            }
        }
        // normalize the xnew vector by dividing with the lambda_new
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
    fprintf(fp2, "\n\nDominant eigenvalue: %f\n ", lambda_new);
   // print the eigenvector
   fprintf(fp2, "\n Eigenvector = \n");
    for (int ii = 0; ii < n; ii++)
    {
        fprintf(fp2, "%f\n", x[ii]);
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}
