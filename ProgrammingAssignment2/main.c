                                                /* COP3502C Assignment 2
                                This program is written by: Dylan Wilkins */
#include <stdio.h>
#include <stdlib.h>

typedef struct Student {
    int sequenceNumber;
    struct Student* next;
} student;

typedef struct queue {
    struct Student* front;
    struct Student* rear;
    int nodeCount;
    int k;
    int th;
    int garNum;
} queue;

// Basic Queue functions
void initQueue(queue *q, int garNum, int k, int th, int nodeCount);
// Operative functions
struct Student* createStudent(int sequence);
void createReverseCircle(queue *q);
void rearrangeCircle(queue* q);
void display(queue *q);
// Phase 1 & Phase 2 functions

struct Student* createStudent(int sequence) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    newStudent->sequenceNumber = sequence;
    newStudent->next = NULL;
    return newStudent;
}

void initQueue(queue *q, int garNum, int k, int th, int nodeCount) {
    q->front = NULL;
    q->rear = NULL;
    q->k = k;
    q->th = th;
    q->nodeCount = nodeCount;
    q->garNum = garNum;
}
void enQueue(queue* q, struct Student* newStudent) {
    if(q->front == NULL && q->rear == NULL) {
        q->front = newStudent;
        q->rear = newStudent;
        q->rear->next = q->front; // connects rear to front, making it circular
    } else {
        q->rear->next = newStudent;
        q->rear = newStudent; // makes newStudent now rear
        q->rear->next = q->front; // connects rear to front, making it circular
    }

}

void createReverseCircle(queue *q) {
    for(int j = q->nodeCount; j > 0; j--) {
        struct Student* newStudent = createStudent(j);
        enQueue(q, newStudent);
    }
}

void rearrangeCircle(queue* q) {
    if(q->front == NULL) { // checks if queue is empty
        return;
    }
    struct Student* current = q->front, *prev = NULL, *next = NULL; // creates necessary pointers for traversing & reversing the queue

    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != q->front);

    q->rear = q->front;
    q->rear->next = prev;
    q->front = prev;
}

void display(queue *q) {
    if(q->front == NULL) {
        return;
    } else {
        struct Student* temp = q->front;
        printf("%d ", q->garNum);
        do {
            printf("%d ", temp->sequenceNumber);
            temp = temp->next;
        } while(temp != q->front);
        printf("\n");
    }
}


void phase1(queue *q) {
    if(q->front == NULL) {
        return;
    }
    printf("\nGroup for Garage# %d\n", q->garNum);
    struct Student *current = q->front, *prev = NULL;

    // loop until we have the desired number of nodes left
    while(q->nodeCount > q->th) {
        // traverse until we find the kth node
        for(int i = 1; i < q->k; i++) {
            prev = current;
            current = current->next;
        }
        if(current == q->front) {
            q->front = current->next;
        }
        if(prev != NULL) {
            prev->next = current->next;
        }
        student *Delete = current; // stores the node to be deleted, then moves to the next node
        current = current->next;
        printf("Studnt# %d eliminated\n", Delete->sequenceNumber);
        free(Delete);
        q->nodeCount--;
    }
}


int main() {
    int garages, garNum, s, k, th;
    scanf("%d", &garages);
    queue q[10];

    //Initialize all garages (queues)
    for(int i = 0; i < 10; i++) {
        q[i].front = NULL;
        q[i].rear = NULL;
    }
    for(int i = 0; i < garages; i++) {
        scanf("%d %d %d %d", &garNum, &s, &k, &th);
        initQueue(&q[garNum], garNum, k, th, s);
        createReverseCircle(&q[garNum]);
    }
    // Prints the initial status of the queues
    printf("Initial status of nonempty queues\n");
    for(int i = 0; i < 10; i++) {
        display(&q[i]);
    }

    for(int i = 0; i < 10; i++) {
        rearrangeCircle(&q[i]);
    }
    printf("After reversing:\n");
    for(int i = 0; i < 10; i++) {
        display(&q[i]);
    }

    printf("\nPhase1 elimination\n");
    for(int i = 0; i < 10; i++) {
        phase1(&q[i]);
    }

    // TODO
    // deQueue, peek, isEmpty
    // // Phase 2 eliminations
}