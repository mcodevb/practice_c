#include <stdio.h>
#include <math.h>
int main() 
{
    const int age=20;
    int time;
    float interest, capital, comp_interest;
    char msg;
    printf("How much did you put into bank?\n");
    scanf("%f", &capital);
    float rate;
    rate = 6.0;
    time = 3;
    printf("Your have put Rs. %8.2f at a rate of %5.2f  for %2d years.\n",capital, rate, time);
    interest = (capital*rate*time)/100;
    comp_interest= capital*pow((1+rate/100.0),time)-capital;
    printf("You will get %5.2f as simple interest\n", interest);
    printf("You will get %5.2f as compound interest\n", comp_interest);
}
