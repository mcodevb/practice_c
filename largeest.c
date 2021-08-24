#include<stdio.h>
int main()
{
    float n1, n2, n3, n4;

    FILE *inputfile, *outputfile;

    inputfile = fopen("input_data.txt", "r");
    outputfile = fopen("output_data.txt","w");

    // We are reading data from a txt file
    fscanf(inputfile, "%f %f %f %f", &n1, &n2, &n3, &n4);

    if (n1>n2 && n1>n3 && n1>n4)
        fprintf(outputfile, "max = %f", n1);
    else if (n2>n1 && n2>n3 && n2>n4)
        fprintf(outputfile, "max = %f", n2);
    else if (n3>n1 && n3>n2 && n3>n4)
        fprintf(outputfile, "max = %f", n3);
    else
        fprintf(outputfile, "max = %f", n4);


    fclose(inputfile);
    fclose(outputfile);

    return 0;
}
