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
    fp1 = fopen("adam_only.dat", "r");
    fp2 = fopen("adam_only.out", "w");
    fscanf(fp1, "%f%f%f%d", &x[0], &h, &tol, &n);
    for ( i = 0; i < 4; i++)
    {
        x[i] = x[0] + i*h;
        fscanf(fp1, "%f", &yp[i]);
        fprintf(fp2, "y(%f)=%f\n", x[i], yp[i]);
    }
    
    for (i = 3; i <= n ; i++)
    {
        yp[i + 1] = yp[i] + (h / 24) * (55 * f(x[i], yp[i]) - 59 * f(x[i - 1], yp[i - 1]) + 37 * f(x[i - 2], yp[i - 2]) - 9 * f(x[i - 3], yp[i - 3]));
        x[i + 1] = x[i] + h;
        // corrector formula
        for ( j = 0; j < maxiter; j++)
        {
            yc[i+1]=yp[i]+(h/24)*(f(x[i-2],yp[i-2])-5*f(x[i-1],yp[i-1])+19*f(x[i],yp[i])+9*f(x[i+1],yp[i+1]));
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