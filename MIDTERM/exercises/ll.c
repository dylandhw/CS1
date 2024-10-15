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


node_t * flipHalf(node_t * head, int n){
    node_t * end = head;
    for(int i = 0; i < n/2; i++){
        end = end->next;
    }
    node_t * newFront = end->next;
    end->next = NULL;
    node_t * tmp = newFront;
    while(tmp->next != NULL){
        tmp = tmp->next;
    }
    tmp->next = head;
    return newFront;
}

node_t * moveHeadNearTail(node_t * head){
    noe_t * temp = head;/*Create a temp node and have it point to head*/
    while(temp->next->next != NULL){
        temp = temp->next; /*Move temp node until second last position*/
    }
    node_t * newFront = head->next; /*Need to create a new front which points to second node*/
    head->next = temp->next; /*Second node now points to temp's next */
    temp->next = head; /*Temp's next now points to head*/

    return newFront;
}


Monster_List* getDefaultMonsters(int n){
    Monster_List res* = malloc(sizeof(Monster_List));

    res->mArray = malloc(sizeof(Monster*)*n);
    res->numMonsters = n;

    for(int i =0; i < n; i++){
        res->mArray[i] = malloc(sizeof(Monster));
        initializeMonster(res->mArray[i]);
    }
    return res;
}

int numDirChange(node *front){
    if(front == NULL || or front->next == NULL || front->next->next == NULL){
        return 0;
    }

    node* a = front;
    node* b = a->next;
    node* c = b->next;
    int res = 0;

    while(c != NULL){
        if(a->data > b->data && b->data < c->data){
            res++;
        }
        if(a->data < b->data && b->data > c->data){
            res++;
        }
        a = b;
        b = c;
        c = c->next;
    }
    return res;
}

void addFront(dequeue* myDequeue, int val){
    node* temp = makeNode(val);
    if(myDequeue->front == NULL){
        myDequeue->front == temp;
        myDequeue->back == temp;
        return;
    }
    temp=temp->next;
    myDequeue->front = temp;
}

void printMixed(node* word1, node* word2){
    while(word1 != NULL || word2 != NULL){
        if(word1 != NULL){
            printf("%c", word1->letter);
            word1 = word1->next;
        } 
        if(word2 != NULL){
            printf("%c", word2->letter);
            word2 = word2->next;
        }
    }
}


node* deleteMe(node* head, node* me){
    if(me == head){
        head = head->next;
    }
    if(me->next != NULL){
        me->next->prev = me->prev;
    }
    if(me->prev != NULL){
        me->prev->next = me->next;
    }
    free(me);
    return head;
}

void insertAfterN(node* head, int m, int n){
    if(head == NULL){
        return;
    }
    if(head->next == N){
        node* temp = malloc(sizeof(node));
        temp->data = m;
        temp->next = head->next;
        head->next = temp;
        head = temp;
        }   
    insertAfterN(head->next, int m, int n);
}

int isPalindrom(char *str){
    struct stack s;
    initialize(&s);
    int len = strlen(str);

    for(int i = 0; i < len; i++){
        push(&s, str[i]);
    }
    for(int i = len-len/2; i < len; i++){ // i guess to make it more efficient ?? because if half isn't the same then it doesn't matter anyway, right?
        if(pop(&s) != str[i]);
        return 0;
    }

    return 1;
}

Employee* createEmployees(char names[][50], double *salaries, int empCount){
    Employee* employees = malloc(sizeof(Employee) * empCount);

    for(int i = 0; i < empCount; i++){
        employees[i].ename = malloc(sizeof(StringType));
        int length = strlen((names[i])+1);
        employees[i].ename->string = malloc(sizeof(char)*length);
        strcpy(employee[i].ename->string, names[i]);
        employees[i].ename->length = length - 1;
        employees[i].salary = salaries[i];
    }
    return employees;
}

struct present* delete_present_list(struct present* present_list, int num){
    int i;
    if(present_list == NULL){
        return NULL;
    }

    for(int i = 0; i < num; i++){
        free(present_list[i].present_name);
    }
    free(present_list);

    return NULL; 
}

int dequeue(struct queue* q){
    if(q == NULL){
        return 0;
    }
    if(q->numElements == 0){
        return 0;
    }
    int retval = q->array[q->front];
    q->front = (q->front+1)%q->capacity;
    q->numElements--;
    return retval;
}

void grow_stack(struct stack* s, int increase){
    int newSize = s->capacity + increase;
    int *hold = s->array;

    s->array = malloc(sizeof(int) * newSize);

    for(int i = 0; i < s->top; i++){
        s->array[i] = hold[i];
    }
    free(hold);

    s->capacity = newSize;
}

struct node* make_circle(struct node* head){
    if(head == NULL){
        return;
    }
    struct node* helper = head;
    while(helper->next != NULL){
        helper = helper->next;
    }
    helper->next = head;

    return head;
}

int check_all_even(struct node* head){
    if(head == NULL){
        return 0;
    }
    if(head->next == NULL){
        if(head->data % 2 == 0){
            return 1;
        } else {
            return 0;
        }
    }
    if(head->data % 2 != 0){
        return 0;
    }
    return check_all_even(head->next);
}


int dequeue(queue *thisQ){
    if(thisQ == NULL){
        return 0;
    }
    if(thisQ->size == 0){
        return 0;
    }
    int retval = thisQ->head->data;
    node *temp = thisQ->head;

    thisQ->head = thisQ->head->next;

    if(thisQ->size > 1){
        thisQ->head->prev = NULL;
    } else {
        thisQ->tail = NULL;
    }
    free(temp);
    thisQ->size--;
    return retval;
}