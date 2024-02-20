// WAP TO FIND THE FACTORIAL OF ANY NUMBER USING RECUSIVE ALGORITHM

#include <stdio.h>
int factorial(int num);

int main() {
  int num;
  printf("Enter any number you want to find the factorial of: ");
  scanf("%d", &num);
  if (num < 0) {
    printf("Error! Factorial of negative number does not exist.");
  }
  printf("The factorial of %d is %d", num, factorial(num));
}

int factorial(int num) {
  if (num == 0 || num == 1) {
    return 1;
  } else {
    return (num * factorial(num - 1));
  }
}