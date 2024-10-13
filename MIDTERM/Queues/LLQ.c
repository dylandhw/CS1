struct Node {
    int data;
    struct Node* next;
};
/*Our queue structure*/
struct Queue {
    struct Node* front; // <- Points to the front for dequeue ops
    struct Node* rear; // <- Points to the rear for enqueue ops
};

void enqueue(struct Queue* q, int value){
    struct Node* temp = (struct Node*)malloc(sizeof(Node));
    temp->data = value;
    temp->next = NULL;

    if(q->rear == NULL){ /*If rear is NULL, our queue is empty, so front should be = to 
    rear which should be = to temp*/
        q->front = q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }
}

int dequeu(struct Queue* q){
    if(q->front == NULL){
        return -1;
    }
    struct Node* temp = q->front;
    int value = temp->data;
    q->front = q->front->next;
    if(q->front == NULL){
        q->rear == NULL
    } else {
        free(temp);
        return value; 
    }
}

int peek(struct Queue* q){
    if(q->front == NULL){
        return -1;
    } else {
        return q->front->data;
    }
}

int empty(struct Queue* q){
    if(q->front == NULL){
        return -1;
    } else {
        return 0;
    }
}