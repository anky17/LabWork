#include <conio.h>
#include <math.h>
#include <stdio.h>
// Defining equation to be solved.
// #define f(x) sin(x) - 1 / x
//  #define f(x) exp(-x)-x
#define f(x) cos(x) - x *exp(x)

int main() {
  // e=tolerable error
  float x0, x1, xm, f0, f1, fm, e;
  int step = 1;
/* Inputs */
up:
  printf("\nEnter two initial guesses:\n");
  scanf("%f%f", &x0, &x1);
  printf("Enter tolerable error:\n");
  scanf("%f", &e);
  /* Calculating Functional Value */
  f0 = f(x0);
  f1 = f(x1);
  /* Checking whether given guesses brackets the root or not. */
  if (f0 * f1 > 0.0) {
    printf("Incorrect Initial Guesses.\n");
    goto up;
  }
  /* Implementing Bisection Method */
  printf("\nStep\t\tx0\t\tx1\t\tx2\t\tf(x2)\n");
  do {
    xm = (x0 + x1) / 2;
    fm = f(xm);
    printf("%d\t\t%f\t%f\t%f\t%f\n", step, x0, x1, xm, fm);
    if (f0 * fm < 0) {
      x1 = xm;
      f1 = fm;
    } else {
      x0 = xm;
      f0 = fm;
    }
    step = step + 1;
  } while (fabs(fm) > e);
  printf("\nRoot is: %f", xm);
  return 0;
}