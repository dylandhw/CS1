#include <stdio.h>
#include <stdlib.h>
#define MAX 50

int queue_array[MAX];
int rear = 0;
int front = 0;

void enQueue(int add){
    if(rear < max){
        queue_array[rear] = add;
        rear++;
        printf(">>>ADDED<<<\n");
    } else {
        printf(">>>QUEUE OVERFLOW<<<\n");
    }
}

