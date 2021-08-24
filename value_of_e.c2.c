#include<stdio.h>
#include<math.h>
int main()
{
    int nterm;
    double e =1.0 , tolerance = 0.5*1e-5;

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
        e = e + term;
        if ( term < tolerance )
        {
         break;
        }
    }

    fprintf(outputfile,"approximate value of e = %.6lf at %dth iteration", e, i);
    
    fclose(inputfile);
    fclose(outputfile);
    return 0;
}
