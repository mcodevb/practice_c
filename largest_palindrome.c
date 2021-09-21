#include<stdio.h>
#include<math.h>

int ispalindrome(int n);

int main()
{


    return 0;
}

int ispalindrome(int num)
{
    // 1 for palindrome numbers and 0 for others
    int temp = num, revnum = 0, remainder;
    while(temp!=0){
        remainder = temp % 10;
        revnum = 10* revnum + remainder;
        temp = temp/10;
    }
    if (revnum == num)
        return 1;
    else
        return 0;
}