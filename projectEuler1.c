#include<stdio.h>
#include<math.h>

int main()
{
    int n, div1, div2, sum;

    FILE *inputfile, *outputfile;
    inputfile = fopen("projE1_input.txt","r");
    outputfile = fopen("projE1_output.txt","w");

    fscanf(inputfile, "%d %d %d", &n, &div1, &div2);

    sum = 0;
    for (int  i = 1; i < n; i++)
    {
        if ((i % div1 == 0)|| (i % div2 ==0) )
        {
            sum = sum+i;
        }
    }

    fprintf(outputfile, "Sum of all multiples of %d or %d within 1 and %d is: %d",div1, div2, n, sum);

    

    fclose(inputfile);
    fclose(outputfile);
    return 0; 
}