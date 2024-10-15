void enqueue(int add){
    if(rear < max){
        queueArray[rear] = add;
        rear++;
    }
}

int dequeue(){
    if(front == rear){
        return empty
    } else {
        return queueArray[front++];
    }
}

int enQueue(struct queue* qPtr, int value){
    if(qPtr->numElements != qPtr->queueSize){
        qPtr->elements[(qPtr->front+qPtr->numElements)%qPtr->queueSize] = value;
        (qPtr->numElements)++;
    } else {
        qPtr->elements = realloc(qPtr->elements, (qPtr->queueSize)*sizeof(int)*2);

        for(int i = 0; i <= qPtr->front-1; i++){
            qPtr->elements[i+qPtr->queueSize] = qPtr->elements[i];
        }
        qPtr->elements[i+qPtr->queueSize] = value;
        (qPtr->queueSize) *= 2;
        (qPtr->numElements)++;
    }
}

int deQueue(struct queue* qPtr){
    int retval;
    if(qPtr == NULL){
        return empty;
    } else {
        retval = qPtr->elemetns[qPtr->front];
        qPtr->front = (qPtr->front + 1)%qPtr->queueSize;

        (qPtr->numElements)++;
    }
    return retval;
}