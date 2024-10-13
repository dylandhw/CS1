#define EMPTY -1
#define INIT_SIZE 10

/*Our circular queue structure*/
struct queue{
    int* elements; /*Pointer to an array of elements*/
    int front;
    int noe;
    int queueSize;
};

/*Initializes all my stuff :p*/
void init(struct queue *qPtr){
    qPtr->elements = (int*)malloc(sizeof(int)*INIT_SIZE);
    qPtr->front = 0;
    qPtr->noe = 0;
    qPtr->queueSize = INIT_SIZE;
}

int enQueue(struct queue* qPtr, int val){
    int i;
    if(qPtr->noe != qPtr->queueSize){ /*This allows us to work with a queue if we have
    previously deleted items from the queue...*/
    /*accesses the element index at front + num of elements, modded by the size, this
    wraps around the queue to the position, then increment num of elements*/
        qPtr->elements[(qPtr->front+qPtr->noe)%qPtr->queueSize] = val;
        (qPtr->noe)++;
    } else {
        for(int i = 0; i < qPtr->front-1; i++){ /*Loops us until the first available position
        */
            qPtr->elements[i+qPtr->queueSize] = qPtr->elements[i];
        }
        qPtr->elements[i+qPtr->queueSize];
    }
}

int deQueue(struct queue* qPtr){
    int retval;
    if(qPtr->noe == 0){
        return -000;
    } else { /*Stores the value to be returned*/
        retval = qPtr->elements[qPtr->front];
        /*Adjusts the front using wraparound*/
        qPtr->front = (qPtr->front + 1)%qPtr->queueSize;
        /*Decrements the number of elements*/
        (qPtr->noe)--;
    }
}