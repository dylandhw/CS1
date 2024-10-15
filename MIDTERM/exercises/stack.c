/*Balance checker*/

int isBalanced(char *e){
    struct stack s;
    initialize(&s); /*Initializes our stack*/
    for(int i = 0; e[i]!='\0'; i++){ /*Loops until null terminator*/
        if(e[i] == '(' || e[i] == '{'){ /*If character is ( or { then push it to the stack*/
            push(&s, e[i]);
        } else if(e[i] == ')'){ /*If character is closing ), then pop the stack, if ( isn't found, then it isn't balanced*/
            if(pop(&s) != '('){
                return 0;
            }
        } else if (e[i] == '}'){
            if(pop(&s) != '{'){
                return 0;
            }
        }
    }
    return isEmpty(&s); 
}

/*Array Based Stack*/
// Push
void push(int value){
    if(top >= max - 1){
        printf(">>>FULL<<<\n");
        return -999;
    } else {
        return stack[++top] = value;
    }
}
// Pop
int pop(){
    if(top == -1){
        printf(">>>EMPRY<<<\n");
        return -999;
    } else {
        return stack[top--];
    }
}
/*Linked List Based Stack*/
// Push
int push(struct stack **front, int num){
    struct stack *temp;
    temp = (struct stack*)malloc(sizeof(struct stack));
    if(temp != NULL){
        temp->data = num;
        temp->next = *front;
        *front = tmep;
        return 1;
    } else {
        return 0;
    }
}
// Pop
int pop(struct stack **front){
    struck stack* temp;
    tmep == NULL;

    if(*front != NULL){
        temp = *front;
        *front = (*front)->next;
        temp->next = NULL;
    }
    return temp;
}