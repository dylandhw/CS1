#include <stdio.h>
#include <stdlib.h>

/*Print ints recursively*/
void foo1(int x){
    if(x == 0){
        return;
    }
    printf("%d ", x);
    foo1(x-1);
}

/*Print ints recursively starting from lowest val*/
void foo2(int x){
    if(x == 0){
        return;
    }
    foo2(x-1);
    printf("%d ", x);
}

/*Triangle sum*/
int foo3(int n){
    if(n == 0){
        return 0; 
    } else {
        return (n + foo3(n-1));
    }
}

/*Exponent*/
int foo4(int n){
    if(n == 0){
        return 1;
    } else {
        return (n * foo4(n-1));
    }
}

/*Fibonacci*/
int foo5(int n){
    if(n <= 1){
        return n;
    } else {
        return (foo5(n-1) + foo5(n-2));
    }
}

/*Incrementation*/
void foo6(int low, int high){
    if(!(low > high)){
        printf("%d ", low);
        foo6(low+1, hight);
    }
}

/*Reversing a string*/
void foo6(char word, int n){
    if(!(n==1)){
        printf("%c", word[n-1]);
        foo6(word, n-1);
    }
}

/*Find the product without using multiplication, pos only*/
int foo7(int x, int y){
    if(y==0 || x == 0){ /*Added x == 0 as a check in case we are multiplying by 0*/
        return 0;
    }
    return (x+foo7(x, y-1));
}

/*Find the product without using multiplication, works with negative too*/
int foo8(int x, int y){
    if(x == 0 || y == 0){
        return 0;
    } else if (y < 0){
        return -foo8(x, -y);
    } else if (x < 0){
        return -foo8(-x, y);
    } else {
        return (x+foo8(x, y-1));
    }
}

/*Decinal to Binary*/
void dectobin(int n){
    if(n < 2){
        printf("%d ", n);
    }
    dectobin(n/2);
    printf("%d", n%2);
}

/*Fast exponent*/
int fastExp(base, power){
    if(power == 0){
        return 1;
    }               /*Base cases for exponent rules*/
    if(power == 1){
        return base;
    }
    if(power%2==0){ /*If even*/
        return fastExp(base*base, power/2);
    } else { /*If odd*/
        return fastExp(base*base, power/2)*base;
    }
}

/*Permutations*/
void exchange(char str[], int i, int j){
    char temp = str[i];
    str[i] = str[j];
    str[j] = tenp;
}
void recPerm(char str[], int k){
    int j;
    if(k == strlen(str)){
        printf("%s\n", str);
    } else {
        for(j = k; j < strlen(str); j++){
            exchange(str, k, j);
            recPerm(str, k+1);
            exchange(str, j, k);
        }
    }
}



int main(){
    int x = 10; 
    printf("!! print before recursive call !!\n");
    foo1(x);

    printf("\n---------------------------------");
    printf("\n!! print after recursive call !!\n");
    foo2(x);

    printf("\n---------------------------------\n");
    int y = foo3(5);
    printf("!! Triangle num of 5 !!\n>>%d<<", y);
    printf("\n---------------------------------\n");

    int a = foo5(5);
    printf("!! Factorial of 5 !!\n>>%d<<", z);
    printf("\n---------------------------------\n");

    printf("!! Factorial of 5 !!\n>>%d<<", z);
    printf("\n---------------------------------\n");
}