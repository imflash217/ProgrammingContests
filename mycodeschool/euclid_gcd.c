#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int euclid_gcd_naive(int a, int b)
{
    int dividend = a >= b ? a : b;
    int divisor = a <= b ? a : b;

    while (divisor != 0)
    {
        int remainder = dividend % divisor;
        dividend = divisor;
        divisor = remainder;
    }
    return dividend;
}

int euclid_gcd_compressed(int a, int b)
{
    while (b != 0)
    {
        int remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}

int euclid_recursive(int a, int b)
{
    return b == 0 ? a : euclid_recursive(b, a % b);
}

int main()
{
    int a = 105;
    int b = 350;
    int gcd_naive = euclid_gcd_naive(a, b);
    int gcd_compressed = euclid_gcd_compressed(a, b);
    int gcd_recursive = euclid_recursive(a, b);
    printf("gcd(%d,%d) = %d\n", a, b, gcd_naive);
    printf("gcd(%d,%d) = %d\n", a, b, gcd_compressed);
    printf("gcd(%d,%d) = %d\n", a, b, euclid_recursive(a, b));
}