#include <stdio.h>
#include<stdlib.h>

float det(float A[10][10], int n);

int main(void)
{
    int n, i, j, k;

    FILE *inputfile, *outputfile;
    inputfile = fopen("determinant_input.txt", "r");
    outputfile = fopen("determinant_output.txt", "w");

    // Input matrix dimension
    fscanf(inputfile, "%d", &n);
    float a[10][10], dett = 0.0;

    // scan the coefficient matrix
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            fscanf(inputfile, "%f", &a[i][j]);
   
    for (int ii = 0; ii < n; ii++)
    {
        for (int jj = 0; jj < n; jj++)
        {
            printf("%f ", a[ii][jj]);
        }
        printf("\n");
    }
    // Calculate determinant
     dett = det(a, n);

    // print determinant  on the terminal

     printf("\n determinant = %f\n", dett);
    


    fclose(inputfile);
    fclose(outputfile);
    return 0;
}

float det(float A[10][10], int n)
{
    float Minor[10][10], determinant = 0;
    int i,j,k;
    if (n==2)
    {   
        determinant = A[0][0]*A[1][1] - A[0][1]*A[1][0];
    }
    else
    {   
        int multiplier = 1;
        for ( i = 0; i < n; i++)
        {   
            int row = 0;
            for ( j = 0; j < n; j++)
            {
                if(j==i)
                   continue;

                for ( k = 1; k < n; k++)
                {
                   Minor[row][k-1] = A[j][k];
                }
                row = row + 1;
            }
            
            determinant += multiplier*A[i][0]*det(Minor, n-1);
            multiplier  = - multiplier;
        }
        

    }
    return determinant;
}