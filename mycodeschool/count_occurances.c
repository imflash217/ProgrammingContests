// find the count of an element in a SORTED array
// time_complexity = O(log(n))
//
#include <stdio.h>
#include <stdlib.h>

int binary_search(int A[], int n, int x, int search_first){
    int start = 0;
    int end = n-1;
    int result = -1;
    while (start <= end){
        int mid = start + (end-start)/2;
        if (x < A[mid]) end = mid - 1;
        else if (x > A[mid]) start = mid + 1;
        else {
            result = mid;
            if (search_first == 0){
                end = mid - 1;      // search on the left half now
            }else{
                start = mid + 1;    // search on the right half now
            }
        }
    }
    return result;
}

int count_occurances(int A[], int n, int x){
    int start = binary_search(A, n, x, 0);
    int end = binary_search(A, n, x, 1);
    int count = end - start + 1;
    return count;
}


int main(){
    int n = 10;
    int x = 15;
    int A[] = {1,2,3,15,15, 15, 15, 15, 35, 45};    // sorted array
    int count = count_occurances(A, n, x);
    printf("count(A, %d) = %d\n", x, count);
}


