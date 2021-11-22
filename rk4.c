#include <stdio.h>
#include <math.h>
float f(float x, float y);

int main()
{
    int i;
    float x, x0, y0, xn, yn, n, h, k1, k2, k3, k4;
    printf("enter the stepsize:");
    scanf("%f", &h);
    printf("enter the value of x, x0, y0");
    scanf("%f %f %f", &x, &x0, &y0);
          n = (x - x0) / h;
          xn = x0;
          yn = y0;
          
    while (xn <= x){
        k1 = h * f(xn, yn);
        k2 = h * f(xn + h / 2, yn + k1 / 2);
        k3 = h * f(xn + h / 2, yn + k2 / 2);
        k4 = h * f(xn + h, yn + k3);

        xn = xn + h;
        yn = yn + (k1 + 2 * k2 + 2 * k3 + k4) / 6;

                      printf("y(%f)=%f\n", xn, yn);
    }
}

float f(float x, float y)
{
    return 2*x;
}