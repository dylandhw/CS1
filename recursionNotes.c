#include <stdio.h>

int factorial(int n){
    if(n == 0){ /*must always have a base case that stops the recursive calls*/
        return 1;
    }
    return n * factorial(n-1); /*recursive case*/
}

void reverseString(char string[], int length){
    if(length == 0){
        return; /*base case*/
    }
    printf("%c", string[length-1]); /*printing first because we want to start at the end*/
    reverseString(string, length-1); 
}

int multiply(int first, int second){
    if(second<=0){ /*base case*/
        return 0;
    }
    return(first+multiply(first, second-1));
}

/*TODO
fast exponent
decimal to binary
tower of hanoi
division
negatives with multiplication
*/