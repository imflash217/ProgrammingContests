#include <stdio.h>
#include <stdlib.h>

void SelectionSort(int A[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int idx_min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[idx_min])
            {
                idx_min = j;
            }
        }
        // swap the elements
        int tmp = A[i];
        A[i] = A[idx_min];
        A[idx_min] = tmp;
    }
}

int main()
{
    int A[] = {11, 1, 3, 2, 0, 90, 112, -1, -5};
    int n = 9;
    SelectionSort(A, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", A[i]);
    }
}