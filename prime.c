// Simple C program to count prime numbers upto n really fast
// Written by Mainul Hossain <getmainul1@gmail.com>
#include <math.h>
#include <stdio.h>  

long long int main() {
    
  long long int n,i,count=1, num=3,flag;
  printf("Choose any integer > 1 to find primes upto that number: ");
  scanf("%lld",&n);
  long long int prime[100000];
      prime[1]=2;
  if (n<2){
      printf("There is no prime between %lld and 1",n);
  } else if (n==2) {
         printf("There is an unique %lld prime between 1 and %lld",prime[count],n);
  } else if (n>2) {
      while(num<=n){
          flag=1;
          for (i = 1; i <= count; i++)
          {
            if (prime[i]<=sqrt(num)){
//                printf("i=%d, prime[i] = %d, num=%d \n",i,prime[i],num);
                if (num%prime[i]==0){
                   flag=0;
                   break;  
                }
            } else {
              break;
            }           
          }
          if (flag==1){
             count++;
             prime[count]=num;
          }
        num=num+2;
      }
      
      // for (i = 1; i <=count; i++) {
      //   printf(" %d \n", prime[i]);
      // }
      printf("There are total %lld prime numbers between 1 and %lld \n",count, n);
  }
  return 0;
}
