#include<math.h>
#include<stdio.h>
int main()
{
    int n1=0,n2=1,n3,i,j;
    printf("Enter the number of terms: ");
    scanf("%d",&j);
    printf("\nFibonacci Series: %d, %d", n1,n2);
    for ( i = 3; i <= j; i++)
    {
        n3=n1+n2;
        printf(", %d",n3);
        n1=n2;
        n2=n3;
    }
    
}