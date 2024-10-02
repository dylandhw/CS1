#include <stdio.h>
#include <stdlib.h>

#define EMPTY -1
#define INIT_SIZE 10

struct queue{
    int* elements;
    int front;
    int numElements;
    int queueSize;
};

void init(struct queue *qPtr);
int enqueue(struct queue *qPtr, int val);
int dequeue(struct queue *qPtr);
int empty(struct queue *qPtr);
int front(struct queue *qPtr);
void displayQueue(struct queue *qPtr);

int main(){
    int choice, data;

    /*Allocate space for our queue*/
    struct queue* MyQueuePtr = (struct queue*)malloc(sizeof(struct queue));
    /*Initialize our queue*/
    init(MyQueuePtr);
    
    while(1){
        printf("\n>>>1. Insert  <<<\n");    
        printf(">>>2. Delete  <<<\n");    
        printf(">>>3. Display <<<\n");    
        printf(">>>4. Quit    <<<\n"); 
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\n>>> DATA <<<\n");
                scanf("%d", &data);
                enqueue(MyQueuePtr, data);
                break;
            case 2:
                data = dequeue(MyQueuePtr);
                if(data != EMPTY){
                    printf("\n>>> '%d' REMOVED from Queue <<<");
                } else {
                    printf("\n>>> EMPTY <<<");
                }
                break;
                case 3:
                    displayQueue(MyQueuePtr);
                    break;   
        }
    }
}

void init(struct queue *qPtr){
    /*Allocate enough space for the elements*/
    qPtr->elements = (int*)malloc(sizeof(int)*INIT_SIZE);
    qPtr->front = 0;
    qPtr->numElements = 0;
    qPtr->queueSize = INIT_SIZE;
}

int enqueue(struct queue* qPtr, int val){
    int i;
    /*If our queue isn't full*/    
    if(qPtr->numElements != qPtr->queueSize){
        /*Learn the use of % in this case*/
        qPtr->elements[(qPtr->front+qPtr->numElements)%qPtr->queueSize] = val;
        (qPtr->numElements)++;

        return 1;
    } else {
        /*If queue is full we must allocate more space*/
        qPtr->elements = realloc(qPtr->elements, (qPtr->queueSize)*sizeof(int)*2);
        /*Copy all items that are stored 'before' front and put them into their new,
        correct locations*/
        for(int i = 0; i < qPtr->front-1; i++){
            qPtr->elements[i+qPtr->queueSize] = qPtr->elements[i];
        }
        /*Enqueue the new item, guranteed no wraparound is needed*/
        qPtr->elements[i+qPtr->queueSize] = val;

        /*Update size of the queue and number of elements*/
        (qPtr->queueSize)*2;
        (qPtr->numElements)++;

        return 1;
    }
}

int dequeue(struct queue* qPtr){
    int retval;

    /*If the queue is empty*/
    if(qPtr->numElements == 0){
        return EMPTY;
    } else {
        /*Store the value that should be returned*/
        retval = qPtr->elements[qPtr->front];
        /*Adjust the index to the front of the queue accordingly*/
        qPtr->front = (qPtr->front + 1)%qPtr->queueSize;
        /*Decrement numelements and return the dequeued value*/
        (qPtr->numElements)--;
        return retval;
    }
}

void displayQueue(struct queue *qPtr){
    if(empty(qPtr)){
        printf(">>> Queue is EMPTY <<<\n");
        return ;
    } else {
        printf("\nCONTENTS\n");
        printf("--------\n");
        if(qPtr->front + qPtr->elements < qPtr->queueSize){
            for(int i = qPtr->front; i < qPtr->front+qPtr->numElements; i++){
                printf("%d ", qPtr->elements[i]);
            }
        } else {
            for(int i = qPtr->front; i < qPtr->queueSize; i++){
                printf("%d ", qPtr->elements[i]);
            }
            for(int i = 0; i < (qPtr->front + qPtr->numElements)%qPtr->queueSize; i++){
                printf("NO VAL ");
            }
        }
    }
    printf("\n");
}

int empty(struct queue *qPtr){
    return qPtr->numElements == 0;
}