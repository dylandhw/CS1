#include <stdio.h>

int factorial(int n){
    if(n == 0){ /*must always have a base case that stops the recursive calls*/
        return 1;
    }
    return n * factorial(n-1); /*recursive case*/
}

/*  Unwinding the recursive calls
    factorial(2) was waiting for the result of factorial(1) which is 1, 
    so now it computes:
    2 * 1 = 2
    factorial(3) was waiting for the result of factorial(2) which is 2,
    so now it computes:
    3 * 2 = 6
    factorial(4) was waiting for the result of factorial(3) which is 6,
    so now it computes:
    4 * 6 = 24
    factorial(5) was waiting for the result of factorial(4) which is 24,
    so now it computes:
    5 * 24 = 120
*/

void reverseString(char string[], int length){
    if(length == 0){
        return; /*base case*/
    }
    printf("%c", string[length-1]); /*printing first because we want to start at the end*/
    reverseString(string, length-1); 
}
/*  Unwinding the recursive calls
    prints(string[length(5)-1], so 'o')
    calls the function of string with (string, length-1(4))
    prints(string[length(4)-1, so'l'])
    calls the function of string with (string, length-1(3))

    This continues until the length is 0, printing 'hello'.  
*/

int multiply(int first, int second){
    if(second<=0){ /*base case*/
        return 0;
    }
    return(first+multiply(first, second-1));
}
/*  Unwinding the recursive calls
    Adds the first value over and over until second is 0
    effectively multiplying the values
*/

int lucas(int n){
    if(n==1){
        return 1;
    }else if(n==2){
        return 3;
    }else{
        return lucas(n-1)+lucas(n-2);
    }
}
/*  Unwinding the recursive calls
    Keeps adding the immediate past two terms
*/

void decToBin(int n){
    if(n<2){
        printf("%d", n);
    } else {
        decToBin(n/2);
        printf("%d", n%2);
    }
}
/*  Unwinding the recursive calls
    Divides n by 2 and prints the remainder until n is < than 2, then prints n (1)
*/

int fastExp(int b, int e){
    if(e == 0){
        return ;
    }
    if(e == 1){
        return b;
    }
    if(e%2 == 0){
        return fastExp(b*b, e/2);
    } else {
        return fastExp(b*b, e/2)*b;
    }
} 

/*TODO
tower of hanoi
*/