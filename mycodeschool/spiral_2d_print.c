// print a 2d array into spiral format
//

#include <stdio.h>
#include <stdlib.h>


void spiral_print(int A[][3], int rows, int cols){
    int top = 0;
    int bottom = rows-1;
    int left = 0;
    int right = cols-1;
    int direction = 0;

    while (top <= bottom && left <= right){
        if (direction == 0){
            // move left-to-right
            printf("[");
            for (int i=left; i<=right; i++){
                printf("%d, ", A[top][i]);
            }
            printf("]\n");
            top++;     // increment top
        }
        else if (direction == 1){
            // move top-to-bottom
            printf("[");
            for (int i=top; i<=bottom; i++){
                printf("%d, ", A[i][right]);
            }
            printf("]\n");
            right--;      // decrement right
        }
        else if (direction == 2){
            // move right-to-left
            printf("[");
            for (int i=right; i>=left; i--){
                printf("%d, ", A[bottom][i]);
            }
            printf("]\n");
            bottom--;    // decrement bottom
        }
        else if (direction == 3){
            // move bottom-to-top
            printf("[");
            for (int i=bottom; i>=top; i--){
                printf("%d, ", A[i][left]);
            }
            printf("]\n");
            left++;   // increment left
        }
        direction = (direction + 1) % 4;     // increment the direction by one and keep it withing 1-to-4 loop
    }
}


int main(){
    int rows = 4;
    int cols = 3;
    int A[4][3] = {
        {1,2,3},
        {5,6,7},
        {9,10,11},
        {13,14,15}
    };

    spiral_print(A, rows, cols);
}
