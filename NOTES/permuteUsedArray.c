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

void mypermute(int arr[], int used[], int k, int n){
    if(k == n){
        printPermuteArray(arr, n);
    }
    for(int i = 0; i < n; i++){
            if(!used[i]){
                used[i] = 1;
                arr[k] = i;
                mypermute(arr, used, k+1, n);
                used[i] = 0;
            }
        }
}
