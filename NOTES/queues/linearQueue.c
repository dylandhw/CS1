#include <stdio.h>
#include <stdlib.h>
#define MAX 50

int queue_array[MAX];
int rear = 0;
int front = 0;

void enQueue(int add){
    if(rear < MAX){
        queue_array[rear] = add;
        rear++;
        printf(">>>ADDED<<<\n");
    } else {
        printf(">>>QUEUE OVERFLOW<<<\n");
    }
}
int deQueue(){
    if (front == rear){
        printf(">>>EMPTY<<<\n");
        return -999;
    } else {
        return queue_array[front++];
    }
}

void display(){
    int i;
    if(front == rear){
        printf(">>>QUEUE IS EMPTY<<<\n");
    } else {
        printf(">>>QUEUE IS: \n");
        for(i = front; i < rear; i++){
            printf("%d ", queue_array[i]);
        }
        printf("\n\n");
    }
}

int main(){
    int choice, data;

    while(1){
        printf("---INSERT(1)---\n");
        printf("---DELETE(2)---\n");
        printf("---DISPLAY(3)---\n");
        printf("---QUIT(4)---\n");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                printf("***DATA?***");
                scanf("%d", &data);
                enQueue(data);
                display();
                break;
            case 2:
                data = deQueue();
                display();
                break;
            case 3:
                display();
                break;
            case 4:
                return 1;
            default:
                printf("---INVALID---\n");            
        }
    }
    return 0;
}