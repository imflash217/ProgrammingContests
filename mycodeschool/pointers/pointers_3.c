#include <stdio.h>
#include <stdlib.h>

int main(){
    int a  = 1025;
    int *ptr;
    ptr = &a;
    printf("a = %d\n", a);
    printf("&a = %d\n", &a);
    printf("ptr = %d\n", ptr);
    printf("*ptr = %d\n", *ptr);

    char *ptr2;
    ptr2 = (char *) ptr;
 
    printf("ptr = %d\n", ptr2);
    printf("*ptr = %d\n", *ptr2);

    char *ptr3;
    ptr3 = &a;
    printf("ptr3 = %d\n", *ptr3);
    *ptr3 = 4;
    printf("*ptr3 = %d\t a = %d\n", *ptr3, a);
}

