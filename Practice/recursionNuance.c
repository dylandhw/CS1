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

}