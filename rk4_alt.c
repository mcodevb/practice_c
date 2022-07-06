#include <stdio.h>
#include<math.h>
float f(float x, float y)
	{
	  float out;
        out = 1+ x*y;
	  return out;
	}
int main()
{
    int i, n;
    float xn, yn, h, k1, k2, k3, k4;
    FILE *fopen(), *fp1, *fp2;
    fp1 = fopen("rk4_alt.dat", "r");
    fp2 = fopen("rk4_alt.out", "w");
    
    fscanf(fp1, "%f %f %f %d", &xn, &yn, &h, &n); // initial cond, stepsize, x
    fprintf(fp2, "y(%f)=%f\n", xn, yn);
    for ( i = 0; i < n; i++)
    {
        k1 = h * f(xn, yn);
        k2 = h * f(xn + h / 2, yn + k1 / 2);
        k3 = h * f(xn + h / 2, yn + k2 / 2);
        k4 = h * f(xn + h, yn + k3);

        xn = xn + h;
        yn = yn + (k1 + 2 * k2 + 2 * k3 + k4) / 6;

        fprintf(fp2,"y(%f)=%f\n", xn, yn);
    }
}
