/*This uses a 'used' array to track whether a number was already used in a particular
iteration of the permutation process*/

#include <stdio.h>
#define SIZE 3

void printPermuteArray(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

