   #include <stdio.h>

   int main (){
       int i = 0;
       printf(" In progress:   0%%");
       for (i = 0; i < 10000; i++){
           printf("\b\b\b\b%3d%%", i/100);
       }
       printf("\n"); 
       fflush(stdout);
   }