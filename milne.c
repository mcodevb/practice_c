#include<stdio.h>
#include<math.h>
float f(float x, float y)
	{
	  float out;
      // out = 1+ x*y;
      // out = x*x+y*y;
       out= (1- x*y)/(x*x);
      //out = (2-y*y)/(5*x);
      // out = (x+y)/2;
	  // out= 2*exp(x)-y;
      // out  = x*pow(y,1.0/3.0);
      // uncomment one of the above ODEs
	  return out;
	}

float main()
{
    int i,j, n, maxiter = 10;
    float k1, k2, k3, k4, h, x[100], y[100], k, yp[100], yc[100], tol, error;
    FILE *fopen(), *fp1, *fp2;
    fp1 = fopen("milne.dat", "r");
    fp2 = fopen("milne.out", "w");
    fscanf(fp1, "%f%f%f%f%d", &x[0], &y[0], &h, &tol, &n);
    for (i = 0; i <= 2; i++)
    {
        k1 = h * f(x[i], y[i]);
        k2 = h * f(x[i] + h / 2.0, y[i] + k1 / 2.0);
        k3 = h * f(x[i] + h / 2.0, y[i] + k2 / 2);
        k4 = h * f(x[i] + h, y[i] + k3);
        k = (k1 + 2 * k2 + 2 * k3 + k4) / 6.0;
        y[i + 1] = y[i] + k;
        x[i + 1] = x[i] + h;
    }
    for (i = 0; i <= 3; i++)
    {
        yp[i] = y[i];
    }
    for (i = 0; i <= 3; i++)
    {
        fprintf(fp2, "y(%f)=%f\n", x[i], y[i]);
    }

    for (i = 3; i <= n + 2; i++)
    {
        // predictor formula
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