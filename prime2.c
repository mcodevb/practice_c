// Simple C program to count prime numbers upto n not so fast
// Written by Mainul Hossain <getmainul1@gmail.com>

#include<stdio.h>
 
int main()
{
    long long int i,j,n;
    
    printf("Enter the number till which you want prime numbers\n");
    scanf("%lld",&n);
    long long int count=0;
    // printf("Prime numbers are:-\n");    
    for(i=2;i<=n;i++)
    {
        int c=0;
        for(j=1;j<=i;j++)
        {
            if(i%j==0)
            {
                c++;
            }
        }
         
       if(c==2)
        {
          //printf(" %d \n",i);
          count++;
        }
    }
    printf("Total prime numbers: %lld \n", count); 

    return 0;
}