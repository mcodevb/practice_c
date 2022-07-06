#include<stdio.h>
int main()
{
 int i,n,r,sum=0;
 printf("enter the value of n: ");
 scanf("%d",&n);
 while(n>1)
 {
   r=n%10;
   n=n/10;
   if(r%2==0)
   {
       printf("%d\n",r);
  sum=sum+r;
   }
 }
printf("sum of the even digits = %d",sum);
 }





