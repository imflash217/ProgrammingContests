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

void BubbleSort(int A[], int n)
{
    int *tmp = (int *)malloc(sizeof(int));
    int *flag = (int *)malloc(sizeof(int));
    *flag = 0;
    for (int k = 0; k < n - 1; k++)
    {
        // single pass
        for (int i = 0; i < n - 1 - k; i++)
        {
            if (A[i] > A[i + 1])
            {
                *tmp = A[i];
                A[i] = A[i + 1];
                A[i + 1] = *tmp;
                *flag = 1;
            }
        }
        printf("\n[k=%d]\t", k);
        print_array(A, n);
        if (*flag == 0)
        {
            printf("[k=%d] flag = %d\n", k, *flag);
            break;
        }
        *flag = 0;
    }
    free(tmp);
}

int main()
{
    int A[] = {-1, -5, 11, 1, 3, 2, 0, 90, 112};
    int n = 9;
    print_array(A, n);
    BubbleSort(A, n);
    print_array(A, n);
}