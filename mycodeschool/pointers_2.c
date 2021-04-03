#include <stdio.h>

int main()
{
    int a = 10001;
    int *p;
    p = &a;             // p -> address of a
    printf("%d\n", p);  // prints the value stored by p
    printf("%d\n", *p); // prints the value stored by the variable referenced by p
    printf("%d\n", &a);
    printf("[before]: a = %d\n", a);
    *p = 12; // de-referencing
    printf("[after]: a = %d\n", a);

    int b = 2021;
    *p = b;
    printf("*p = %d\n", *p);
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("---------");
    printf("int = %lu bytes", sizeof(int));
}