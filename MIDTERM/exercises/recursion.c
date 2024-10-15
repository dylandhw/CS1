/*Recursively free all the nodes in a linked list*/

void recFree(struct Node* head){
    /*Base case: if the node is empty*/
    if(head == NULL){
        return;
    }
    /*Free the next node first, our recursive call*/
    recFree(head->next);
    /*Gets pushed back*/
    free(head);
}

/*Recursive function permutation using swapping technique*/
void TOH(int n, char from, char to, char aux){
    if(n==1){
        printf("Move disk 1 from rod %c to rod %c", from, to);
        return;
    }
    TOH(n-1, from, aux, to);

    printf("Move disk %d from rod %c to rod %c", n, from, to);

    TOH(n-1, aux, to, from);    
}


int power(int a, int b){
    if(b == 0){
        return 1;
    } else {
        return a * power(a, b-1);
    }
}
int crazySum(int n){
    if(n == 1){
        return 1;
    } else {
        return power(n, n) + crazySum(n-1);
    }
}

void decToOct(int decimal){
    if(decimal == 0){
        return;
    }
    decToOct(decimal / 8);
    printf("%d", decimal%8);
}

int zeros(int n){
    if(n == 0){
        return 0; 
    } else {
        return n/5 + zeros(n/5);
    }
}

int productDigits(int n){
    if(n < 10){
        return n;
    } else {
        return (n%10) * productDigits(n/10);
    }
}

int isSorted(int *array, int n){
    if(n < 2){ /*If there is only one item it has to be sorted*/
        return 1;
    } else {
        if(array[n-1] < array[n-2]){ /**/
            return isSorted(array, n-1);
        }
    }
}