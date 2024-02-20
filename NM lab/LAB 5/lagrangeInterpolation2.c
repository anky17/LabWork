// WAP TO IMPLEMENT LAGRANGE INTERPOLATION USING C.

#include <stdio.h>

int main() {
  double x[100], y[100], xp, yp = 0, p;
  int i, j, n;

  // Prompt user for the number of data points
  printf("Enter the number of data: ");
  scanf("%d", &n);

  // Input x and y values
  for (i = 0; i < n; i++) {
    printf("Enter x[%d] and y[%d]: ", i, i);
    scanf("%lf %lf", &x[i], &y[i]);
  }

  // Input the x value at which to interpolate the value of y
  printf("Enter interpolation point: ");
  scanf("%lf", &xp);

  // Compute the Lagrange interpolation
  for (i = 0; i < n; i++) {
    p = 1;  // Reset p for each term of the polynomial
    for (j = 0; j < n; j++) {
            if (i != j) {  // To prevent divide by 0.
        p *=
            (xp - x[j]) / (x[i] - x[j]);  // Compute each term of the polynomial
      }
    }
    yp += p * y[i];  // Add the term to the final result
  }

  // Output the result
  printf("Interpolated value at %lf is %lf.\n", xp, yp);
  return 0;
}
