#include<stdio.h>
#include<math.h>
float f(float x, float y)
	{
	  float out;
	  out= (2*y)/x;
	  return out;
	}

float main()
{
    int i, n;
    float k1, k2, k3, k4, h, x[100], y[100], k, yp[100], yc[100], eps, err, l;
    FILE *fopen(), *fp1, *fp2;
    fp1 = fopen("adambash_input.txt", "r");
    fp2 = fopen("adambash_output.txt", "w");
    fscanf(fp1, "%f%f%f%f%d", &x[0], &y[0], &h, &eps, &n);
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
    for (i = 0; i <= 2; i++)
    {
        fprintf(fp2, "y(%f)=%f\n", x[i], y[i]);
    }

    for (i = 3; i <= n + 2; i++)
    {
        // predictor formula
        yp[i + 1] = yp[i] + (h / 24) * (55 * f(x[i], yp[i]) - 59 * f(x[i - 1], yp[i - 1]) + 37 * f(x[i - 2], yp[i - 2]) - 9 * f(x[i - 3], yp[i - 3]));
        // fprintf(fp2,"yptest=%f\n",yp[i+1]);
        x[i + 1] = x[i] + h;
        // corrector formula
loop:    yc[i+1]=yp[i]+(h/24)*(f(x[i-2],yp[i-2])-5*f(x[i-1],yp[i-1])+19*f(x[i],yp[i])+9*f(x[i+1],yp[i+1]));
        // fprintf(fp2,"yctest=%f\n",yc[i+1]);
        l = yp[i + 1] - yc[i + 1];
        // fprintf(fp2,"l=%f\n",d);
        err = fabs(yp[i + 1] - yc[i + 1]);
        // fprintf(fp2,"d=%f\n",d);
        if (err < eps)
            fprintf(fp2, "y(%f)=%f\n", x[i + 1], yc[i + 1]);
        else
        {
            yp[i + 1] = yc[i + 1];
            fprintf(fp2, "yptest2=%f\n", yp[i + 1]);
            goto loop;
        }
        yp[i + 1] = yc[i + 1];
    }

    fclose(fp1);
    fclose(fp2);
}