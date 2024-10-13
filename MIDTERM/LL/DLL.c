#include <stdio.h>
#include <stdlib.h>

/*Structure of a doubly linked list node*/
struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};

void insertBeginning(struct Node** head, int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = (*head);
    newNode->prev = NULL;

    if(*head != NULL){
        (*head)->prev = newNode; /*Links heads previous to the new node if head isn't empty (i.e if list ins't empty)*/
    }
    (*head) = newNode; /*Makes the new node head*/
}

void insertEnd(struct Node** head, int data){
    struct Node* new = (struct Node*)malloc(sizeof(Node)); /*new node*/
    struct Node* last = *head; /*our traversal node (will also be last node)*/
    new->data = data;
    new->next = NULL;

    if(*head == NULL){ /*checks if the list is empty*/
        new->prev = NULL; /*if list is empty there will be no prev*/
        *head = new;
        return;
    }

    while(last->next != NULL){ /*traverses our list*/
        last = last->next;
    }
    last->next = new; /*last (temp) node now points to the new node*/
    new->prev = last; /*new node's prev points to last (temp)*/
}

node* delete(Node** head, int data){ /*COME BACK AND ANNOTATE*/
    Node *t;
    Node *temp;
    if(head == NULL){
        return head; 
    }
    if(head->data == data){
        temp = head;
        head = head->next;
        if(head != NULL){
            head->prev == NULL;
            free(temp);
            return head;
        }
    }
    t = head;
    while(t->next != NULL && t->next->data != data){
        t = t->next;
    }
    if(t->next == NULL){
        return head;
    }
    temp = t->next;
    t->next = t->next->next;
    if(t->next){
        t->next->prev = t;
        free(temp);
        return head;
    }
} 