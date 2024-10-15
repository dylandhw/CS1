/*Linked List Implementation of a Queue*/
// Enqueue
void enqueue(struct queue *q, int value){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;
    temp->next = NULL;

    if(q->back == NULL){
        q->front = NULL;
        q->back = NULL;
    } else {
        q->back->next = temp;
        q->back = temp;
    }
}

// Dequeue
int dequeu(struct queue* q){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp = q->front;
    int retval = temp->data;

    q->front = q->front->next;

    if(q->front == NULL){
        q->back == NULL;
    }
    free(temp);
    return retval;
}

/*Linear Queue (array based)*/
// Enqueue
void enqueue(struct queue* q, int value){
    if(rear < MAX){
        queueArr[rear] = value;
        rear++;
        return 0;
    } else {
        printf("overflow\n");
        return -1;
    }
}

int dequeue(struct queue* q){
    if(front == rear){
        printf("empty\n");
        return -1;
    } else {
        return queueArr[front++];
    }
}

// Circular Queue 
int enQueue(struct queue* q, int value){
    if(qPtr->elements != qPtr->queueSize){
        qPtr->elements[(qPtr->front + qPtr->noe)%qPtr->queueSize] = value;
        (qPtr->noe)++;
    } else {
        qPtr->elements = realloc(qPtr->elements, (qPtr->queueSize)*sizeof(int)*2);
    
        for(int i = 0; i < qPtr->front-1; i++){
            qPtr->elements[i+qPtr->queueSize] = qPtr->elements[i];
        }
        qPtr->elements[i+qPtr->queueSize] = value;

        (qPtr->queueSize)*2;
        (qPtr->noe)++;

        return 1;
    }
}

int dequeue(struct queue* qPtr){
    int retval;
    if(qPtr->noe == 0){
        return empty;
    } else {
        retval = qPtr->elements[qPtr->front];
        qPtr->front = (qPtr->front+1)%qPtr->queueSize;
        (qPtr->noe)--;
        return retval;
    }
}