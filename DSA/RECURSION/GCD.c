// WAP TO FIND THE GCD  OF ANY TWO GIVEN NUMBER USING RECURSIVE ALGORITHM

#include <stdio.h>
int GCD(int num1, int num2);

int main()
{
    int a, b;
    printf("Enter any two number: ");
    scanf("%d%d", &a, &b);
    printf("The GCD of %d and %d is %d", a, b, GCD(a, b));
}

int GCD(int num1, int num2)
{
    if (num1 % num2 == 0) // if in some case like 2 % 4 == 2, we need to change the position of the parameters in the recursive call.
    {
        return num2;
    }
    else
    {
        return GCD(num2, num1 % num2);
    }
}