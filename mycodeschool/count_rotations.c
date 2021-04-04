// count the number of rotations in a sorted circular array 
//
#include <stdio.h>
#include <stdlib.h>

int count_rotations(int A[], int n){
    // A[] is a circular sorted array
    int start = 0;
    int end = n-1;

    while (start <= end){
        int mid = start + (end-start)/2;
        if (A[start] <= A[end]) return start;
        int prev = (mid - 1 + n)%n;
        int next = (mid + 1)%n;
        if (A[prev] >= A[mid] && A[mid] <= A[next]){
            // case-1: then we got the pivot
            return mid;
        }
        else if (A[mid] <= A[end]){
            // right half is sorted; so discard it
            end = mid - 1;
        }
        else if (A[mid] >= A[start]){
            // left half is sorted; so discard it
            start = mid + 1;
        }
    }
    return -1;      // we could not find any valid scenario i.e the array is invalid
}

int main(){
    int n = 5;
    int A[] = {5,6,10,2,3};
    int num_rotations = count_rotations(A, n);
    printf("%d\n", num_rotations);
}
