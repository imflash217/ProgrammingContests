#include <stdio.h>
#include <stdlib.h>

void print_array(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", A[i]);
    }
    printf("\n");
}

void InsertionSort(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int value = A[i]; // save the value to be placed in the sorted part
        int hole = i;     // create a "hole" at the current index

        // move the hole till we find a place to insert the "value"
        while (hole > 0 && A[hole - 1] > value)
        {
            A[hole] = A[hole - 1]; // insert the left-side value into the hole
            hole--;                // move the hole to the left
        }
        A[hole] = value; // insert the value at the last valid-hole
    }
}

int main()
{
    int A[] = {-1, -5, 11, 1, 3, 2, 0, 90, 112};
    int n = 9;
    print_array(A, n);
    InsertionSort(A, n);
    print_array(A, n);
}