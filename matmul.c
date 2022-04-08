#include<stdio.h>
int main()
{
    int i,j,k,l,m,n,p;
    float a[10][10], b[10][10], c[10][10];
    FILE *inputfile, *outputfile;
    inputfile = fopen("matmul_input.txt","r");
    outputfile = fopen("matmul_output.txt","w");

    fscanf(inputfile,"%d %d %d", &m,&n, &p);
    fprintf(outputfile,"A(%d,%d) times B(%d,%d):\n",m,n,n,p);
   
    for ( i = 0; i < m; i++)
        for ( j = 0; j < n; j++)
            fscanf(inputfile,"%f",&a[i][j]);

    for ( i = 0; i < n; i++)
        for ( j = 0; j < p; j++)
            fscanf(inputfile,"%f",&b[i][j]);
    

    for ( i = 0; i < m; i++)
    {
        for ( j = 0; j < p; j++)
        {
            float sum = 0.0;
            for ( k = 0; k < n; k++)
            {
                sum = sum + a[i][k] * b[k][j];
                printf("%f\n",sum);
            }
            c[i][j] = sum;
        }
        
    }
    
    // print matrix
    for ( j = 0; j < p; j++)
    {
        for ( i = 0; i < m; i++)
            fprintf(outputfile," %.3f ",c[i][j]);
    
        fprintf(outputfile,"\n");
    }

    fcloseall;
}