#define MAX 100
int stack[MAX];
int top = -1;

void push(int value){
    if(top >= MAX -1){
        printf("overflow\n");
        return;
    } else {
        stack[++top] = value;
    }
}

int pop(){
    if(top == -1){
        printf("underflow\n");
        return -1;
    }
    return stack[top--];
}

int peek(){
    if(top == -1){
        printf("empty\n")
        return -1;
    }
    return stack[top];
}

int empty(){
    return top == -1;
}

// that should be everything ?? 