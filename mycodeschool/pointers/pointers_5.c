#include <stdio.h>
#include <stdlib.h>

void increment(int *ptr){
    *ptr += 1;  // increment the value stored in the variable whose address is stored in this "ptr"
}

int main(){
    int a = 10;
    printf("before [a = %d]\n", a);
    increment(&a);     // increment the value inside variable "a"
    printf("after [a = %d]\n", a);
}
