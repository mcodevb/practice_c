// Bisection method in C
#include<stdio.h>
#include<math.h>

float f(float x);


int main()
{
    int   n, i;
    float a, b, fa, fb, midpt, tol;
    FILE *inputfile, *outputfile;

    inputfile = fopen("bisection_input.txt","r");
    outputfile = fopen("bisection_output.txt","w");
    fscanf(inputfile, "%f %f %f", &a, &b, &tol);
    fprintf(outputfile, "a = %f, b = %f, tolerance = %f \n", a, b, tol);
    fa = f(a);
    fb = f(b);
    fprintf(outputfile, "f(%f) = %f, f(%f) = %f \n", a, fa, b, fb);


    fclose(inputfile);
    fclose(outputfile);
    return 0;
}


float f(float x)
{
    return x*x-5*x+6;
}