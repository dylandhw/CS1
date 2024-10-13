Struct node {
    int data;
    int node* next;
}

void addN(struct node* list, int n){
    while(list != null){ /*list != NULL so that it includes the last node*/
        list->data += n;
        list = list->next;
    }
}

struct node* deleteFirst(struct node* list){
    if(list == NULL){
        return NULL;
    } else {
        struct node* new = list->next; /*new points to list's next*/
        free(list); /*Frees the current head*/
        return new; /*Returns the new pointer*/
    }
}

struct node* copy(struct node* list){
    struct node* newList = NULL;
    struct node* curEnd  = NULL;
    while(list != NULL){
        struct node* new = malloc(sizeof(struct node));
        new->data = list->data
        new->next = list->NULL;
        if(newList == NULL){
            newList = new;
            curEnd = new;
        } else {
            curEnd->next = new;
            curEnd = curEnd->next;
        }
    }
}

int isSorted(struct node* list){
    if(list == NULL || list->next == NULL){
        return 1;
    }
    int curval = list->data;
    list = list->next;
    while(list != NULL){
        if(curval > list->data){
            return 0;
        } else {
            curval = list->data;
            list = list->next;
        }
    }
    return ;
}

void insertToPlace(struct node* list, int val, int place){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    int count = 1;
    /*Iterate to spot before place*/
    while(list->next != NULL && count < place - 1){ /*Iterates until the spot before place*/
        list = list->next;
        count++:
    }
    temp->next = list->next; /*New node now points to places next. essentially stealing that place*/
    list->next = temp; /*List place now pointst to temp*/
}

void list_42(struct node* list){
    struct node* current = list;
    struct node* temp;
    while(current != NULL){
        if(current->data == 4){
            temp = (struct node*)malloc(sizeof(struct node));
            temp->data = 2;
            temp->next = current->next;
            current->next = temp->next;
        }
    }
}