#include <stdio.h>

struct stack{
    int data;
    struct stack *next;
};
int push(struct stack **front, int num);
struct stack* pop(struct stack **front);
int empty(struct stack *front);
int top(struct stack *front);
void init(struct stack **front);

int main(){
    struct stack *stack1, *temp;
    int tempval;

    init(&stack1);
    if(!push(&stack1, 3)){
        printf("Push Failed...\n");
    }
    if(!push(&stack1, 5)){
        printf("Push Failed...\n");
    }
    temp = pop(&stack1);
    if(temp != NULL){
        printf("Popped From Stack = %d\n", temp->data);
    }
    if(empty(stack1)){
        printf("Stack is Empty.\n");
    } else {
        printf("Stack is *Not* Empty.\n");
    }
    tempval = top(stack1);
    if(tempval != -1){
        printf("Top of Stack = %d\n", tempval);
    }
    temp = pop(&stack1);
    temp = pop(&stack1);
    if(temp != NULL){
        printf("Top of Stack = %d\n", temp->data);
    } else {
        printf("Cannot Pop an Empty Stack.\n");
    }
    return 0;
}

void init(struct stack **front){ /*initializes our struct*/
    *front == NULL;
}
int push(struct stack **front, int num){
    struct stack *temp; /*creates a temp node*/
    temp = (struct stack *)malloc(sizeof(struct stack));
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
        temp = *front;
        *front = (*front)->next; /*if the stack isn't empty, assign temp to the front
        move front up to the next, make temp NULL, return temp*/
        temp->next = NULL;
    }
    return temp;
}

int empty(struct stack *front){
    if(front == NULL){
        return 1; 
    } else {
        return 0;
    }
}

int top(struct stack *front){
    if(front != NULL){
        return front->data;
    } else {
        return -1;
    }
}