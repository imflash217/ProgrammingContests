// QUICK SORT
// Runtime complexity:  Average case ->> O(n.log_n)
//                      Worst case   ->> O(n^2)
// In-place sorting algorithm
// Worst-case runtime can be improved by doing RANDOMIZED QUICK SORT
//
// Step-1: Choose a PIVOT
// Step-2: Partition the array into two parts 
//          a. Left-part -> elements smaller than PIVOT
//          b. right-part -> elements greater than PIVOT
// Step-3: Recursively do QUICK_SORT (steps 1,2,3) into these two left & right parts
//

#include <stdio.h>
#include <stdlib.h>

void print(int A[], int n){
    printf("A = [");
    for (int i=0; i<=n-1; i++){
        printf("%d, ", A[i]);
    }
    printf("]\n");
}

int do_partition(int A[], int start, int end){
    /*
     * A[] -> the array to sort
     * start -> the start index of the array
     * end -> the end index of the array
     */

    // step-1: select the PIVOT
    // we select the last element as pivot
    int pivot = A[end];
    printf("pivot = %d\n", pivot);
    int tmp;

    // step-2: inititalize the partition index (p_idx)
    int p_idx = start;
    
    // step-3: walk through the whole array and partition the array
    for (int i=start; i<end; i++){
        if (A[i] <= pivot){
            // swap the elements
            tmp = A[i];
            A[i] = A[p_idx];
            A[p_idx] = tmp;

            p_idx++;  // increment the partition index
        }
    }
    // lastly, swap the pivot and value @ p_idx
    A[end] = A[p_idx];
    A[p_idx] = pivot;
    return p_idx;
}


void quick_sort(int A[], int start, int end){
    /*
     * A[] -> the array to sort
     * start -> the start index of the array
     * end -> the end index of the array
     */

    // base case
    if (start >= end){
        // in above if-condition:
        // "=" is used to exit when there is only element in the array
        // ">" is used when the array is invalid (eg. empty array)
        return;
    }
    int p_idx = do_partition(A, start, end);    // do partition; returns the partition index
    quick_sort(A, start, p_idx - 1);            // run quick sort on left part
    quick_sort(A, p_idx + 1, end);              // run quick sort on the right part
    print(A, end-start+1);
}

int main(){
    int A[] = {4,5,1,3,7,8,9,10,-9,-1,-99,100};
    int n = 12;
    int start = 0;
    int end = n-1;
    quick_sort(A, start, end);    // run quick_sort
    print(A, n);
}

