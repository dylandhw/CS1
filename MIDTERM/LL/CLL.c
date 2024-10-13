struct Node{
    int data;
    struct Node* next;
};

void insert(struct Node** head, int data){
    struct Node* new = (struct Node*)malloc(sizeof(Node));
    struct Node* temp = *head;
    new->data = data;
    new->next = *head;

    if(*head == NULL){
        *head = new;
        new->next = *head;
    } else {
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new;
    }
} /*Come back to !!!*/