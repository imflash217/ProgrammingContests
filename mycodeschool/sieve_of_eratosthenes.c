#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void SieveOfEratosthenes(int n)
{
    int *IsPrime = (int *)malloc(n * sizeof(int));

    for (int i = 0; i <= n; i++)
    {
        IsPrime[i] = 1;
        printf("(%d, %d) ", i, IsPrime[i]);
    }

    IsPrime[0] = 0;
    IsPrime[1] = 0;
    for (int i = 0; i <= sqrt(n); i++)
    {
        if (IsPrime[i] == 1)
        {
            for (int j = 2; i * j <= n; j++)
            {
                IsPrime[i * j] = 0;
            }
        }
    }

    printf("\n");
    for (int i = 0; i <= n; i++)
    {
        if (IsPrime[i] == 1)
        {
            printf("(%d, %d) ", i, IsPrime[i]);
        }
    }
}

int main()
{
    SieveOfEratosthenes(16);
}