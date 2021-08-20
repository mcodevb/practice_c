#include<stdio.h>
int main(){
    int num, revnum=0, rem, quotient, ndigit=0;
    printf(" Give a number to check whether it's a palindrome: ");
    scanf("%d", &num);
    printf("\n You have entered: %d\n",num);
    quotient=num;
    while(quotient!=0){
        rem=quotient%10;
        revnum=10*revnum+rem;
        quotient=quotient/10;
        ndigit=ndigit+1;
    }

    printf(" The reverse number is: %d \n", revnum);
    if(num==revnum){
        printf(" %d is a palindrome number.", num);
    } else {
        printf(" %d is not a palindrome number.", num);
    }
    
    printf("\n %d has %d digits",num,ndigit);
    return 0;
}