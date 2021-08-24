#include<stdio.h>
#include<math.h>
int main()
{
    int n1, n2, gcd, lcm;

    FILE *inputfile, *outputfile;

    inputfile = fopen("input_data.txt", "r");
    outputfile = fopen("output_data.txt","w");
    
    
    lcm = n1 * (n2 / gcd);

    fclose(inputfile);
    fclose(outputfile);
    return 0;
}