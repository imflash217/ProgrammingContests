// search for an integer in a sorted circular array

#include <stdio.h>
#include <stdlib.h>

int search(int A[], int n, int x){
    int start = 0;
    int end = n-1;
    
    while (start <= end){
        int mid = start + (end-start)/2;
        // base case
        if (A[mid] == x) return mid;
        if (A[mid] <= A[end]){
            // right half is sorted
            if (x > A[mid] && x <=  A[end]){
                // x lies in the right half; so search here
                start = mid + 1;
            }
            else{
                // x does not lie here; so search the left half
                end = end - 1;
            }
        }
        else if (A[mid] >= A[start]){
            // left half is sorted
            if (x < A[mid] && x >= A[start]){
                // x lies here; so search here
                end = mid - 1;
            }
            else{
                // x does not lie here; search on the right half
                start = mid + 1;
            }
        }
    }
    return -1;  // x not found
}


int main(){
    int n = 5;
    int x = 100;
    int A[] = {100,2,21,34,99};
    int idx = search(A, n, x);
    printf("%d\n", idx);
}
