// C program to find the number of subsets with odd cardinality
#include <stdio.h>
long factorial(int);
long ncr(int, int);
int main(){
   int n, r;
   long n_sub;
   printf("Enter the number of elements of the set A: ");
   scanf("%d",&n);
   n_sub = 0;
   for (int i = 1; i <= n; i = i+2) // increment by 2 ensures odd cadinality
   {
     n_sub = n_sub + ncr(n,i);  // number of subsets with i elements
   }
   
   printf("Number of subsets of A with odd number of elements = %ld\n", n_sub);
   return 0;
}

long ncr(int n, int r) {
   long result;
   result = factorial(n)/(factorial(r)*factorial(n-r));
   return result;
}

long factorial(int n) {
   int c;
   long result = 1;
   for (c = 1; c <= n; c++)
   result = result*c;
   return result;
}