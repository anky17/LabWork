// WAP TO FIND THE ROOT OF THE GIVEN FUNCITON USING NEWTON RAPHSON METHOD

#include <stdio.h>
#include <math.h>
#define error 0.0001

double f(double x)
{
    return x * log10(x) - 1.2;
}

double f_prime(double x)
{
    return 0.43429 + log10(x);
}

double nRaphson(double x)
{
    double x_next = x;
    double fx, fpx;
    int iter = 1;
    printf("\nIteration\tx_next\t\tf(x)\n");
    while (1)
    {
        fx = f(x_next);
        fpx = f_prime(x_next);
        printf("%d\t\t%lf\t%lf\n", iter, x_next, fx);
        if (fabs(fx) < error)
        {
            break;
        }
        x_next = x_next - fx / fpx;
        iter++;
    }
    return x_next;
}

int main()
{
    double x0, root;
    printf("Enter the inital guess: ");
    scanf("%lf", &x0);
    root = nRaphson(x0);
    printf("The root is = %lf", root);
    return 0;
}