#include <stdio.h>
#include <math.h>
double f(double x)
{
    // Define the function whose root is to be found
    return pow(x, 3) - 4 * x - 9;

    // return pow(x, 3) - x - 1;
    // return exp(-x)-x;
}
double false_position(double a, double b, double tol, int max_iter)
{
    // Implement the false position method to find the root of the function
    double fa = f(a);
    double fb = f(b);
    double c, fc; // c is used to find next root and fc is used to check whether it is positive or nagative.
    int iter = 0;
    printf("Iteration\t a\t\t b\t\t c\t\t f(c)\n");
    do
    {
        c = (a * fb - b * fa) / (fb - fa);
        fc = f(c);
        printf("%d\t\t %f\t %f\t %f\t %f\n", iter, a, b, c, fc);
        if (fc * fa > 0)
        {
            a = c;
            fa = fc;
        }
        else
        {
            b = c;
            fb = fc;
        }
        iter++;
    } while (fabs(fc) > tol && iter < max_iter);
    // The fabs() function takes a single argument (in double) and returns the absolute value of that number (also in double).
    return c;
}
int main()
{
    double x, y;
    printf("Enter the initial guess x: \n");
    scanf("%lf", &x);
    printf("Enter the initia guess y: \n");
    scanf("%lf", &y);
    if (f(x) * f(y) < 0)
    {
        double root = false_position(x, y, 0.0001, 100);
        printf("The root is: %f\n", root);
    }
    else
    {
        printf("Wrong guess try again.......!");
    }
    return 0;
}