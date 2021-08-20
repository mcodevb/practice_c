// Count number of digits in a given number
#include<stdio.h>
int main(){
    int n1, n2, n3, ndigit=0;
    FILE *finput, *foutput;
    
    finput = fopen("input_data.txt","r");
    foutput = fopen("output_data.txt","w");

 //   printf("Give a number to calculate it's number of digit(s)");
    fscanf(finput,"%d %d %d",&n1, &n2, &n3);
    fprintf(foutput,"You have entered: %d %d %d",n1, n2, n3);
    
    if (n1>n2){
        if (n3<n2){
            fprintf(foutput,"\n Numbers in ascending order: %d %d %d", n3, n2, n1);
            fprintf(foutput,"\n Numbers in descending order: %d %d %d", n1, n2, n3);
        }else if (n3>n2 && n3<n1) {
            fprintf(foutput,"\n Numbers in ascending order: %d %d %d", n2, n3, n1);
            fprintf(foutput,"\n Numbers in descending order: %d %d %d", n1, n3, n2);
        } else {
            fprintf(foutput,"\n Numbers in ascending order: %d %d %d", n2, n1, n3);
            fprintf(foutput,"\n Numbers in descending order: %d %d %d", n3, n1, n2);
        }

    } else{
        if (n3<n1){
            fprintf(foutput,"\n Numbers in ascending order: %d %d %d", n3, n1, n2);
            fprintf(foutput,"\n Numbers in descending order: %d %d %d", n2, n1, n3);
        }else if (n3>n1 && n3<n2) {
            fprintf(foutput,"\n Numbers in ascending order: %d %d %d", n1, n3, n2);
            fprintf(foutput,"\n Numbers in descending order: %d %d %d", n2, n3, n1);
        } else {
            fprintf(foutput,"\n Numbers in ascending order: %d %d %d", n1, n2, n3);
            fprintf(foutput,"\n Numbers in descending order: %d %d %d", n3, n2, n1);
        }        
    }



    fclose(finput);
    fclose(foutput);
    return 0;
}