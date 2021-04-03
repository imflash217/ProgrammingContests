// pointers as function returns

#include <stdio.h>
#include <stdlib.h>

int Add_vanilla(int a, int b)
{
    int c = a + b;
    return c;
}

int Add_pointer(int *a, int *b)
{
    int c = *a + *b;
    return c;
}

int *Add_pointer2(int *a, int *b)
{
    int *c = (int *)malloc(sizeof(int));
    *c = *a + *b;
    printf("a = [%d] | b = [%d]\n", a, b);
    printf("c = [%d] | *c = [%d]\n", c, *c);
    return c;
}

int main()
{
    int x = 2;
    int y = 3;
    // int z = Add_vanilla(x, y);
    // int z = Add_pointer(&x, &y);
    int *z = Add_pointer2(&x, &y);
    printf("Hariom\n");
    printf("Sum = %d\n", *z);
    printf("x = [%d] | y = [%d]\n", x, y);
    printf("[Address] &x = [%d] | &y = [%d]\n", &x, &y);
}