#include <stdio.h>
#include <stdlib.h>

/*Structure of a singly linked list node*/
struct Node {
    int data;
    struct Node* next;
};

/*Insertion*/

void insertBeginning(struct Node** head, int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(Node));
    newNode->data = data; /*Fills out the data*/
    newNode->next = (*head); /*head is in () as to not dereference the double pointer*/
    (*head) = newNode; /*Make newNode the new head*/
}

void insertEnd(struct Node** head, int data){   
    struct Node* newNode = (struct Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if(*head == NULL){ /*If the linked list is empty, we must insert it at the head*/
        *head = newNode;
        return;
    }
    struct Node* t = (struct Node*)malloc(sizeof(Node));
    while(t->next != NULL){ /*Loops until it finds the end using a temporary traversal node*/
        t = t->next;
    }
    t->next = newNode; /*Temporary traveral node is now at the end of the linked list so
    it should point to the new node. */
}

void deleteFirst(struct Node** head){
    if(*head == NULL){ /*Checks if the list is empty*/
        return;
    }
    struct Node* temp = *head; /*Assigns a new temporary node to point to the head of the list*/
    *head = (*head)->next; /*Head is now what head's next points to*/
    free(temp); /*Free the head that was to be deleted*/
}

void delete(struct Node** head, int key){
    struct Node* temp = *head;
    struct Node* prev = NULL;

    if(temp != NULL && temp->data == key){
        *head = temp->next;
        free(temp);
        return;
    }
    while(temp != NULL ** temp->data != key){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        return; /*If the key isn't found*/
    }
    prev->next = temp->next;
    free(temp);
}