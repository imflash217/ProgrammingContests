#include <stdio.h>
#include <stdlib.h>

int BinarySearch(int A[], int n, int x)
{
    int start = 0;
    int end = n - 1;

    while (start <= end)
    {
        // int mid = (int)(start + end) / 2;
        int mid = start + (end - start) / 2; // avoids overflow
        // printf("%d\t", mid);
        if (x < A[mid])
        {
            end = mid - 1;
        }
        else if (x > A[mid])
        {
            start = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

int BinarySearchRecursive(int A[], int start, int end, int x)
{
    // base case
    if (start > end)
    {
        return -1;
    }
    // recursive checks
    int mid = start + (end - start) / 2;
    if (x < A[mid])
    {
        return BinarySearchRecursive(A, start, mid - 1, x);
    }
    else if (x > A[mid])
    {
        return BinarySearchRecursive(A, mid + 1, end, x);
    }
    else
    {
        return mid; // x == A[mid]
    }
}

int main()
{
    int n = 5;
    int A[] = {1, 2, 3, 445, 543};
    int x = 1;
    int idx = BinarySearchRecursive(A, 0, n - 1, x);
    // int idx = BinarySearch(A, n, x);
    printf("%d\n", idx);
}