// WAP TO FIND THE ROOT OF THE GIVEN FUNCTION USING FIXED POINT ITERATION .

#include <stdio.h>
#include <math.h>
#define e 0.0001
// Function to define f(x)
double f(double x)
{

    return (exp(-x) - x);
}

// Function to define g(x)

double g(double x)
{

    return exp(-x);
}

int main()
{
    double x0, x;
    int iteration, i;
    printf("Enter the initial guess: ");
    scanf("%lf", &x0);
    // printf("Enter the tolerable error: ");
    // scanf("%lf", &tolerance);
    printf("Enter the no of iteration: ");
    scanf("%d", &iteration);
    printf("\nIterations\tx\tf(x)\n");
    for (i = 1; i <= iteration; i++)
    {

        x = g(x0);
        printf("\n%d\t%lf\t%lf", i, x, f(x));
        if (fabs(x - x0) < e)
        {
            printf("\nConvergered to solution x=%lf after %d iteration.\n", x, i);
            return 0;
        }
        x0 = x;
    }
    printf("\nFailed to converge within the %d iterations\n", iteration);
    return 0;
}