#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;                          // goes into the stack
    int *p;                         // goes into the stack
    p = (int *)malloc(sizeof(int)); // malloc returns a void*; so we need typecasting
    *p = 10;
    free(p);

    p = (int *)malloc(20 * sizeof(int));
    p[0] = 999;     // this is a valid way to assign value to array
    *(p + 1) = 123; // this is also a valid way to assign values to array
    printf("%d\n", p[0]);
    printf("%d\n", *p);
    printf("%d\n", p[1]);
    printf("%d\n", *(p + 1));
}