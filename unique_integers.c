#include<stdio.h>
int main()
{
    int i, j, k, n, a[100], count;
    FILE *inputfile, *outputfile;
    inputfile = fopen("unique_integers_input.txt","r");
    outputfile = fopen("unique_integers_output.txt","w");
    fscanf(inputfile,"%d",&n);
    for ( i = 0; i < n; i++)
    {
        fscanf(inputfile,"%d",&a[i]);
    }
    int visited = -1324;
    for ( i = 0; i < n; i++)
    {
        if(a[i]==visited)
            continue;
        else
        {
            count = 1;
            for ( j = i+1; j < n; j++)
            {
                if (a[j]==a[i])
                {   
                    count = count + 1;
                    a[j] = visited;
                }
                
            }
            fprintf(outputfile,"%d occurs %d times\n",a[i],count);
            
        }

    }
    
    

    fcloseall;
    return 0;
}