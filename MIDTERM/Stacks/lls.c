struct stack {
    int data;
    struct stack *next;
};

int push(struct stack **front, int num){
    struct stack *temp;
    temp = (struct stack*)malloc(sizeof(stack));
    if(temp != NULL){
        temp->data = num;
        temp->next = *front;
        *front = temp;
        return 1;
    } else {
        return 0;
    }
}

struct stack* pop(struct stack **front){
    struct stack *temp;
    temp == NULL;

    if(*front != NULL){
        temp = *front; /*Store our front in temp*/
        *front = (*front)->next; /*Move front up*/
        temp->next = NULL; /*Make temp point to NULL
        fully disconnecting it from our linked list*/
    }
    return temp; /*Return temp*/
}

int empty(struct stack *front){
    if(front == NULL){
        return 1;
    } else {
        return 0;
    }
}

int top(struct stack *front){
    if(front != NULL){ /*If the stack isn't empty, return the front's data*/
        return front->data;
    } else {
        return -1;
    }
}