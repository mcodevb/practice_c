// Bisection method 
#include<stdio.h>
#include<math.h>

float f(float x);


int main()
{
    int   maxiter;
    float a, b, mid, tol;
    FILE *inputfile, *outputfile;

    inputfile = fopen("bisection_input.txt","r");
    outputfile = fopen("bisection_output.txt","w");
    fscanf(inputfile, "%f %f %f %d", &a, &b, &tol, &maxiter);
    fprintf(outputfile, "a = %f, b = %f, tolerance = %f ,\nmaximum number of iteration = %d \n \n", a, b, tol, maxiter);
 
    if (f(a) * f(b) > 0.0)
    {
        printf("Change the values of a and/or b.\n");
    } 
    else
    {

    int rootfound = 0, count = 0;

     while (rootfound == 0)
     {
        
        if (count > maxiter)
        {
            fprintf(outputfile, "maximum iteration reached.\n");
            break;
        }
        count = count + 1;

        if(fabs(f(a)) < tol)
        {
            fprintf(outputfile, "Approximate value of the root is: %f", a);
            rootfound = 1;
        }
        else if (fabs(f(b)) < tol)
        {
            fprintf(outputfile, "Approximate value of the root is: %f", b);
            rootfound = 1;
        }
        else
        {
            mid = (a+b)/2.0;
            if (f(a) * f(mid) < 0.0)
                b = mid;
            else
                a = mid; 
        }
     }
    }


    // fprintf(outputfile, "f(%f) = %f, f(%f) = %f \n", a, fa, b, fb);


    fclose(inputfile);
    fclose(outputfile);
    return 0;
}


float f(float x)
{
    return x*x-5*x+6;
}