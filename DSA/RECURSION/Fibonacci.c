// WAP TO FIND THE NTH FIBONACCI SERIES USING RECURSIVE ALGORITHM.

#include <stdio.h>
int fibonacci(int num);

int main() {
  int num, i;
  printf("How many numbers? ");
  scanf("%d", &num);
  printf("Fibonacci Series:\n");
  for (i = 1; i <= num; i++) {
    printf("%d ", fibonacci(i));
  }
}

int fibonacci(int num) {
  if (num == 0) {
    return 0;
  } else if (num == 1) {
    return 1;
  } else {
    return (fibonacci(num - 1) + fibonacci(num - 2));
  }
}