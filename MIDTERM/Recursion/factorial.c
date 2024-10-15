void rec2(int x){
    if(x == 0){
        return; /*This is our breaking condition that will result in poppint the function
        call stack*/
    }
    rec2(x-1); /*Recursively calls our function*/
    printf("%d", x); /*This gets pushed to the stack*/
}

int power(int base, int exponent){
    if(exponent == 0){
        return 1;
    } else {
        return (base*power(base, exponent-1));
    }
}

int factorial(int n){
    if (n == 0){ /*n == 0 as base case and not n == 1 because we have to multiply by the
    most recent*/
        return 1;
    } else {
        return (n*factorial(int n-1));
    }
}

int fibonacci(int n){
    if(n <= 1){ /*could also do n < 2*/
        return n;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

void reverse(char string[], int len){
    if(n == 1){
        printf("%c", string[0]);
    } else {
        printf("%c", string[n-1]);
        reverse(string, n-1);
    }
}

int product(int a, int b){
    if(b == 0){
        return 0;
    } else {
        return (a + product(a, b-1));
    }
}

// to work for negatives

int prodNeg(int a, int b){
    if(b < 0){
        return -prodNeg(a, -b);
    } else if (a < 0){
        return -prodNeg(-a, b);
    } else {
        return (a + prodNeg(a, b-1));
    }
}

int lucas(int n){
    if (n == 1){
        return 1;
    } else if (n == 2){
        return 3;
    } else {
        return lucas(n-1) + lucas(n-2);
    }
}

void decToBin(int n){
    if(n < 2){
        printf("%d", n);
    } else {
        decToBin(n/2);
        printf("%d", n%2);
    }
}

void hanoi(int n, char from, char to, char aux){
    if(n == 1){
        printf("Move disk 1 from rod %c to rod %c", from , to);
        return;
    } 
    hanoi(n-1, from, aux, to);
    printf("Moved disk %d from rod %c to rod %c", n, from, to);
    hanoi(n-1, aux, to, rod);
}

int fastExp(int base, int power){
    if(exp == 0){
        return 1;
    } else if (exp == 1){
        return base;
    } else if (exp % 2 == 0){
        return fastExp(base*base, exp/2);
    } else if (exp % 2 != 0){
        return fastExp(base*base, exp/2)*base;
    }
}

int binSearch(int *values, int low, int high, int searchVal){
    int mid;
    if(low <= high){
        mid = (low+high)/2;
        if(searchval < values[mid]){
            return binSearch(values, low, mid-1, searchval);
        } else if (searchVal > values[mid]){
            return binSearch(values, mid+1, high, searchval);
        } else {
            return 1;
        }
    }
}
/*This is the brute force solution*/
/*Runtime of n^2*/

void printMatches(int list1[], int list2[], int len1, int len2){
    int i, j;
    for(i = 0; i < len1; i++){
        for(j = 0; j < len2; j++){
            if(list1[i] == list2[j]){
                printf("%d", list1[i]);
                break;
            }
        }
    }
}

/*If both are of the same size, we can use binary search and take logn steps*/
/*We have to repeat this n times so nlogn */

void slmpLinear(int list1[], int n, int list2[], int n){
    int i = 0, j =0;
    while(i < n && j < m){
        if(list1[i] == list2[j]){
            i++
        } else if(list2[j] < list1[i]){
            j++
        } else {
            printf("%d", list1[i]);
            i++;
            j++; 
        }
    }
}

