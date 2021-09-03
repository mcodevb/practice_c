#include <stdio.h>
#include <math.h>
float f(float x);
float derivative(float x);
int main()
{
    int maxiter;
    float x, tol;
    FILE *inputfile, *outputfile;
    int count=0;
    inputfile = fopen("newral_input.txt", "r");
    outputfile = fopen("newral_output.txt", "w");
    fscanf(inputfile, "%f %f %d", &x, &tol, &maxiter);
    fprintf(outputfile, "x = %f, tolerance = %f ,\nmaximum number of iteration = %d \n \n", x, tol, maxiter);
    while (fabs(f(x)) >= tol)
    {
       x=x-f(x)/derivative(x);
   
    if (count > maxiter)
    {
        fprintf(outputfile, "maximum iteration reached.\n");
        break;
    }
        count++;
        if(fabs(f(x)) < tol)
        {
            fprintf(outputfile, "Approximate value of the root is: %f", x);
            break; 
        }
 
    }


    fclose(inputfile);
    fclose(outputfile);
    return 0;

}
float f(float x)
{
    return x*x-5*x+6;
}
float derivative(float x)
{
    return 2*x-5;
}