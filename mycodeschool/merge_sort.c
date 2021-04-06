// merge sort
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


void merge(int L[], int R[], int A[], int nL, int nR){
    // merging the two sorted portions of the array
    // L -> sorted left array
    // R -> sorted right array
    // A -> the original parent array
    int i = 0;  // the index to track L[]
    int j = 0;  // index to track R[]
    int k = 0;  // index to track A[]
    
    printf("xoxox %d, %d\n", nL, nR); 
    
    while (i < nL && j < nR){
        // none of the left or right arrays are fully exhausted
        if (L[i] < R[j]){
            A[k] = L[i];    // copy samllest element to the main parent array
            i = i + 1;      // increment the index of the left array
        }else{
            A[k] = R[j];    // copy smallest element into the parent array
            j = j + 1;      // increment the index of right array
        }
        k = k + 1;          // increment the index of the parent array
    }
    // copy the rest of the leftover elements into the parent array
    while (i < nL){
        A[k] = L[i];
        i = i + 1;
        k = k + 1;
    }
    while (j < nR){
        A[k] = R[j];
        j = j + 1;
        k = k + 1;
    }
    print(A, nL+nR);
}

void merge_sort(int A[], int n){
    // n -> length of the array
    int mid = n / 2;    // the middle index
     
    // base case (only one element or empty array)
    if (n < 2){
        return;
    }
    
    // create the left and right children
    int *L = (int*) malloc(mid * sizeof(int));
    int *R = (int*) malloc((n - mid) * sizeof(int));
    for (int i = 0; i <= mid-1; i++){
        // copy the left part of the array into left child
        L[i] = A[i];
    }
    for (int i = mid; i <= n-1; i++){
        // copy the right part of the array into the right child
        R[i-mid] = A[i];
    }
    // call the merge_sort recursively on left and right halves
    merge_sort(L, mid); 
    merge_sort(R, n-mid);
    // now, merge the left and the right halves
    merge(L, R, A, mid, n-mid);
}

int main(){
    int A[] = {10,2,9,7,5,4,7};
    int n = (int) sizeof(A) / sizeof(*A);
    printf("wow %d\n", n);
    merge_sort(A, 7);
} 
