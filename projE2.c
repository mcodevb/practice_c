#include <stdio.h>
#include <math.h>

int main()
{
    int nmax, num1, num2, fib, sum;

    FILE *inputfile, *outputfile;
    inputfile = fopen("projE2_input.txt", "r");
    outputfile = fopen("projE2_output.txt", "w");

    fscanf(inputfile, "%d", &nmax);
    printf("%d", n);

    num1 = 1;
    num2 = 2;

    sum = 2;

    while (num1 + num2 < nmax)
    {
        fib = num1 + num2;
        num1 = num2;
        num2 = fib;

        if (fib % 2 == 0)
        {
            sum += fib;
        }
    }

    fprintf(outputfile, "Sum of all even Fibonacci numbers below %d is: %d", nmax, sum);

    fclose(inputfile);
    fclose(outputfile);
    return 0;
}