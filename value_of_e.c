#include<stdio.h>
#include<math.h>
int main()
{
    int nterm;
    double e_old = 1.0, tolerance = 0.5*1e-5;

    FILE *inputfile, *outputfile;

    inputfile = fopen("input_data.txt", "r");
    outputfile = fopen("output_data.txt","w");

    // We are reading data from a txt file
    fscanf(inputfile, "%d", &nterm);

    double term = 1.0, e_new;
    int i =1;
    for (i = 1; i < nterm; i++)
    {
        term = term/i;
        e_new = e_old + term;
        if ( fabs(e_new-e_old) < tolerance )
        {
         break;
        }
        e_old = e_new;
    }

    fprintf(outputfile,"approximate value of e = %.6lf at %dth iteration", e_new, i);
    
    fclose(inputfile);
    fclose(outputfile);
    return 0;
}
