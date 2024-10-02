#include <stdio.h>
#include <stdlib.h>
#define EMPTY -1

struct node{
    int data;
    struct node* next;
};


struct queue{
    struct node* front;
    struct node* back;
};

void init(struct queue* q);
int enqueue(struct queue* q, int val);
int dequeue(struct queue* q);
void display(struct queue* q);

void init(struct queue* q){
    q->front = NULL;
    q->back = NULL;
}

int enqueue(struct queue* q, int val){
    // need to create a new temp node
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    // fill out the node
    temp->data = val;
    temp->next = NULL;

    // check if queue is empty, if it is, set both front and back
    if(q->back == NULL){
        q->front = temp;
        q->back = temp;
    } else {
        q->back->next = temp; // the last node now points to the new temp node
        q->back = temp; // the last node is now temp
    }
}

int dequeue(struct queue* q){
    // save current front node to a temp pointer
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp = q->front;
    int retval = temp->data;

    q->front = q->front->next; // moves second in line to front of line

    // if front now becomes null, it means the queue is empty so we have to update the back as well
    if(q->front == NULL){
        q->back = NULL;
    }

    free(temp);
    return retval;
}

void display(struct queue* q){
    struct node* traversal = q->front; // creates a new node and points it to the front of the queue, why don't we malloc?
    while(traversal){
        printf("%d ", traversal->data);
        traversal = traversal->next;
    }
}

int main(){
    int choice, data, i;

    // allocate space for the queue and initialize it
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    init(q);

    while(1){
        printf("\n1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Quit\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Data to Insert: ");
                scanf("%d", &data);
                enqueue(q, data);
                display(q);
                break;
            case 2:
                data = dequeue(q);
                if(data != EMPTY){
                    printf("\nDeleted From Queue: %d\n", data);
                    display(q);
                } else {
                    printf("Queue is Empty\n");
                }
                break;
            case 3:
                display(q);
                break;
            case 4:
                exit(1);
            default:
                printf("Invalid Choice\n");
        }
    }
    
    return 0;
}

