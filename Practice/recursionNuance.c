#include <stdio.h>
#include <stdlib.h>

void foo1(int x){
    if(x == 0){
        return;
    }
    printf("%d ", x);
    foo1(x-1);
}

void foo2(int x){
    if(x == 0){
        return;
    }
    foo2(x-1);
    printf("%d ", x);
}

int foo3(int n){
    if(n == 0){
        return 0; 
    } else {
        return (n + foo3(n-1));
    }
}

int foo4(int n){
    if(n == 0){
        return 1;
    } else {
        return (n * foo4(n-1));
    }
}

int foo5(int n){
    if(n <= 1){
        return n;
    } else {
        return (foo5(n-1) + foo5(n-2));
    }
}

void foo6(int low, int high){
    if(!(low > high)){
        printf("%d ", low);
        foo6(low+1, hight);
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