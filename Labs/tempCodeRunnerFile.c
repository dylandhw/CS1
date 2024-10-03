#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* create(int data);
struct node* insert(struct node* list, int d);
struct node* del(struct node* list, int d);
void print(struct node* list);
void freeList(struct node* list);
void copy(struct node *q, struct node **s);

int main(){
    int number = 0, choice = 0;
    struct node *pList = NULL;
    struct node *nList = NULL;

    while(choice != 4){
        printf("\nDo you want to (1)insert, (2)delete, (3)Copy (4)quit.\n");    
        scanf("%d", &choice);
        printf("Your choice is %d\n", choice);

        if (choice == 1){
        // Get the number.
            printf("Enter the value to insert\n");
            scanf("%d", &number);
            pList = insert(pList, number);
            // Look at the list.
            printf("Items in linked list: ");
            print(pList);
            //printf("\n");
        } else if (choice == 2){
            printf("Enter the value to delete.\n");
            scanf("%d", &number);
            pList = del(pList, number);
            // Look at the list.
            printf("Items in linked list: ");
            print(pList);
            //printf("\n");
        } else if (choice == 3){
            if (nList){
                freeList(nList);
            }
            copy(pList, &nList); //passing reference of nList as it is not
            // returning anything
            // Look at the list.
            printf("Items in NEW linked list: ");
            print(nList);
            printf("\n");
        } else {
            break;
        }
    }
    freeList(nList);
    freeList(pList);
    printf("\nBye..\n");
    return 0;
}

struct node* create(int data){
    struct node* newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct node* insert(struct node* list, int data){
    if(list == NULL || list->data >= data){
        struct node* newNode = create(data);
        newNode->next = list;
        return newNode;
    }
    list->next = insert(list->next, data);
    return list;
}

struct node* del(struct node* list, int d){
    if(list == NULL){
        return NULL;
    }
    if(list->data == d){
        struct node* temp = list->next;
        free(list);
        return temp;
    } else {
        list->next = del(list->next, d); /*list->next because if the next node is the
        one being deleted, we need to update the pointer of list->next*/
        return list;
    }
}

void print(struct node* list){
    if(list == NULL){
        return;
    }
    printf("->%d", list->data);
    print(list->next); /*print(list->next) because we are just calling a print function
    with a new pointer (list->next)*/
}

void copy(struct node *q, struct node **s){
    if(q == NULL){
        *s == NULL;
        return;
    }
    *s = create(q->data); /*we create a new node with the data from the source list
    (q), we then recursively call copy for the next node (q->next) passing the address
    of the next pointer of the new node*/
    copy(q->next, &((*s)->next)); 
    /*each recursive call sets the next pointer of the previously created node
    to point to the newly created node, effectively linking the nodes*/
}

void freeList(struct node* list){
    if(list == NULL){
        return;
    }
    freeList(list->next);
    free(list);
}

/*
When traversing we can just do function(node pointer)
When modifying we have to save it to a new pointer:
list->next = function(node pointer);

*/