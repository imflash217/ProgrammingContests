#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    printf("Enter the size of the array:");
    int n;
    scanf("%d\n", &n);
    int *ptr = (int *)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", i);
        ptr[i] = i + 1;
        // ptr[i] = pow(i, 2);
        // *(ptr + i) = pow(i, 2);
        // printf("%d\n", ptr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", ptr[i]);
    }
}