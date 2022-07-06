#include<stdio.h>
#include<math.h>
float f(float x, float y)
	{ 
      return (1- x*y)/(x*x);
	}

float main()
{
    int i,j, n, maxiter = 10;
    float h, x[100], k, yp[100], yc[100], tol, error;
    FILE *fopen(), *fp1, *fp2;
    fp1 = fopen("milne_only.dat", "r");
    fp2 = fopen("milne_only.out", "w");
    fscanf(fp1, "%f%f%f%d", &x[0], &h, &tol, &n);
    for ( i = 0; i < 4; i++)
    {
        x[i] = x[0] + i*h;
        fscanf(fp1, "%f", &yp[i]);
        fprintf(fp2, "y(%f)=%f\n", x[i], yp[i]);
    }
    
    for (i = 3; i <= n ; i++)
    {
        yp[i + 1] = yp[i-3] + (4*h / 3) * (2 * f(x[i], yp[i]) - f(x[i - 1], yp[i - 1]) + 2* f(x[i - 2], yp[i - 2]));
        x[i + 1] = x[i] + h;
        // corrector formula
        for ( j = 0; j < maxiter; j++)
        {
           yc[i+1]=yp[i-1]+(h/3)*(f(x[i-1],yp[i-1])+4*f(x[i],yp[i]) + f(x[i+1],yp[i+1]));
           error = fabs(yp[i + 1] - yc[i + 1]);
             if (error < tol)
                {
                    fprintf(fp2, "y(%f)=%f\n", x[i + 1], yc[i + 1]);
                    break;  // the moment yc and yp are close enough, stop iterating
                }
             else
                {
                    yp[i + 1] = yc[i + 1];
                }
        }
    }   
    fclose(fp1);
    fclose(fp2);
}