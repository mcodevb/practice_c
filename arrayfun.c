#include <stdio.h>
float displayNumbers(float num[10][10]);

int main() {
  float num[10][10]; // declare variables
  printf("Enter 4 numbers:\n");
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      scanf("%f", &num[i][j]);
    }
  }

  // pass multi-dimensional array to a function
  float aa = displayNumbers(num);
  printf("sum = %f",aa);
  return 0;
}

float displayNumbers(float num[10][10]) {
  float sum=0.0;
  printf("Displaying:\n");
  for (int i = 0; i < 2; ++i) {

    for (int j = 0; j < 2; ++j) {
      printf("%f\n", num[i][j]);
      sum += num[i][j];
    }
  }
  return sum;
}