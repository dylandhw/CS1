#define MAX 50
int queue[MAX];
int front = 0, rear = 0;

void enQueue(int add){
    if(rear < MAX){
        queue[rear] = add; /*Rear is now the value to be added*/
        rear++; /*Increment rear up*/
        printf("added\n");
    } else {
        printf("overflow\n");
    }
}

/*Something of note:
we aren't **actually** deleting anything, we are simply
ignoring it from now on.*/
int deQueue(){
    if(front == rear){
        printf("empty\n");
        return -999;
    } else {
        return queue[front++]; /*Returns the front value and increments it up by 1*/
    }
}

void display(){
    int i;
    if(front == rear){
        printf("empty\n");
    } else {
        printf("queue is: \n");
        for(i = front; i < rear; i++){
            printf("blahhh the actual stuff i'm too lazy\n");
        }
    }
}   