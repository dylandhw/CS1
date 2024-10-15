Stuct node{
    int data;
    Int node* next;
};

void addN(struct node* list, int n){
    while(list != NULL){
        list->data += n;
        list = list->next;
    }
}

struct node* deleteFirst(struct node* list){
    if(list == NULL){
        return NULL;
    } else {
        struct node* newFront = list->next;
        free(list);
        return newFront;
    }
}

struct node* copy(struct node* list){
    struct node* newList = NULL;
    struct node* end = NULL;

    while(list != NULL){
        struct node* new = (struct node*)malloc(sizeof(struct node));
        new->data = list->data;
        new->next = NULL; 
        if(newList == NULL){     // check if new is empty
            newList = new;
            end = new;
        } else {
            end->next = new;    // insert
            end = new;
        }
        list = list->next; // traverse
    }
    return newList;
}

int isSorted(struct node* list){
    if(list == NULL || list->next == NULL){
        return 1;
    }
    int current = list->data;
    list = list->next;
    while(list != NULL){
        if(current > list>data){
            return 0;
        } else {
            current = list->data;
            list = list->next;
        }
    }
    return 1;
}

void insertToPlace(struct node* list, int val, int place){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    int count = 1;
    while(list->next != NULL && count < place - 1){
        list = list->next;
        count++;
    }
    temp->next = list->next;
    list->next = temp;    
}

void list42(struct node* list){
    struct node* current = list;
    struct node* temp;

    while(current != NULL){
        if(current->data == 4){
            temp = (struct node*)malloc(sizeof(struct node));
            temp->data = 2;
            temp->next = current->next;
            current->next = temp;
        }
        current = current->next;
    }
}

struct node* moveFrontToBack(struct node* alpha){
    struct node* newHead;
    struct node* iteration;
    if(alpha == NULL){
        return NULL;
    }
    if(alpha->next == NULL){
        return alpha;
    }
    newHead = alpha->next; /*Stores our new head*/
    iteration = alpha;

    while(iteration->next != NULL){
        iteration = iteration->next;
    }
    iteration->next = alpha; /*Last node now points to original head*/
    alpha->next = NULL; /*Cuts it off, ensuring last node & not circular*/

    return newHead;
}

int push(struct stack **front, int num){
    struct stack *temp;
    temp = (struct stack*)malloc(sizeof(stack));
    if(temp != NULL){
        temp->data = num;
        temp->next = *front;
        *front = temp;
    } else {
        return error;
    }
}

struct stack* pop(struct stack **front){
    struct stack *temp;
    temp == NULL;

    if(*front != NULL){
        temp = *front;
        *front = (*front)->next;
        temp->next = NULL;
    }
    return temp;
}

int enQueue(struct queue* q, int val){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->next = NULL;

    if(q->back == NULL){
        q->front = temp;
        q->back = temp;
    } else {
        q->back->next = temp;
        q->back = temp;
    }
}

int deQueue(struct queue *q){
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
