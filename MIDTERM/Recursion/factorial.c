int factorial(int n){
    if(n == 0){
        return 1;
    } else {
        return n * factorial(n-1); /*This causes n to multiply by itself - 1 over and over until n == 0*/
    }
}

void reverseString(char string[], int length){
    if(length == 0){
        return;
    }
    printf("%c", string[length-1]);
    reverseString(string, length-1);
}/*Prints the last letter then calls the function with the next last letter and so on so forth*/
int multiply(int first, int second){
    if(second <= 0){
        return 0;
    }
    return(first+multiply(first, second)); /*Adds the first number to itself how ever many second times*/
}

void decimalToBinary(int n){
    if(n < 2){
        printf("%d", n);
    } else {
        decimalToBinary(n/2);
        printf("%d", n%2);
    }
}
/*Steps:
move n-1 disks from source to aux
move nth disk from source to dest
move n-1 disks from aux to dest*/
void hanoi(int n, char from, char to, char aux){
    if(n == 0){
        return;
    }
    hanoi(n-1, from, aux, to);
    printf("Move disk %d from rod %c to %c", n, from, to);
    hanoi(n-1, aux, to, from);
}