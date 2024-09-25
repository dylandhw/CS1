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

int deQueue(queue* q) {
    if (q->front == NULL) {
        return -1; // Queue is empty
    }

    struct Student* temp = q->front;
    int value = temp->sequenceNumber;

    if (q->front == q->rear) { // Only one node in the queue
        free(temp); // Free the last student
        q->front = NULL;
        q->rear = NULL;
        return value;
    } else {
        q->front = q->front->next; // Move front to the next student
        q->rear->next = q->front; // Keep it circular
        free(temp); // Free the removed student
    }

    q->nodeCount--; // Decrement node count
    return value; // Return the number of the removed student
}


int peek(queue *q) {
    if(q->front != NULL) {
        return q->front->sequenceNumber;
    }
    return -1;
}

void display(queue *q) {
    if(q->front == NULL) {
        return;
    } else {
        struct Student* temp = q->front;
        printf("%d ", q->garNum);
        do {
            printf("%d", temp->sequenceNumber);
            temp = temp->next;
            if(temp != q->front) {
                printf(" ");
            }
        } while(temp != q->front);
        printf("\n");
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




void phase1(queue *q) {
    if(q->front == NULL) {
        return;
    }
    printf("\nGroup for Garage# %d\n", q->garNum);
    struct Student *current = q->front, *prev = q->rear; // Start prev as rear

    // loop until we have the desired number of nodes left
    while(q->nodeCount > q->th) {
        // traverse until we find the kth node
        for(int i = 1; i < q->k; i++) {
            prev = current; // Move prev to current
            current = current->next; // Move current to next
        }

        // Remove current from the queue
        if(current == q->front) {
            q->front = current->next; // Update front if needed
        }
        prev->next = current->next; // Bypass current
        if (current == q->rear) { // If current is rear, update rear
            q->rear = prev;
        }

        student *Delete = current; // stores the node to be deleted
        current = current->next; // Move to the next node
        printf("Student# %d eliminated\n", Delete->sequenceNumber);
        free(Delete);
        q->nodeCount--;
    }
}

void phase2(queue* q) {
    int remainingQueues = 0;
    for (int i = 1; i <= 10; i++) {
        if (q[i].front != NULL) {
            remainingQueues++;
        }
    }
    while(remainingQueues >= 1) {
        int max = 0, garage;
        for(int i = 1; i <= 10; i++) {
            if(q[i].front != NULL) {
                int front = peek(&q[i]);
                if(front > max) {
                    max = front;
                    garage = q[i].garNum;
                } else if (front == max) {
                    if(q[i].garNum < garage) {
                        garage = q[i].garNum;
                    }
                    garage = garage;
                }
            }
        }

        int value = deQueue(&q[garage]);

        if(q[garage].front == NULL) {
            remainingQueues--;
        }
        if(value) {
            printf("Eliminated student %d from group for garage %d\n", value, garage);
        }
        if(remainingQueues == 1 ) {
            for(int i = 1; i <= 10; i++) {
                if(q[i].front != NULL && q[i].nodeCount == 1) {
                    printf("\nStudent %d from the group for garage %d is the winner!", q[i].front->sequenceNumber,
                           q[i].garNum);
                    free(q[i].front);
                    return;
                }
            }
        }
    }
}



int main() {
    int garages, garNum, s, k, th;
    scanf("%d", &garages);
    queue q[11]; // Array of 11 queues to allow indexing from 1 to 10

    // Initialize all garages (queues)
    for (int i = 1; i <= 10; i++) {  // Start from 1, not 0
        q[i].front = NULL;
        q[i].rear = NULL;
    }

    for (int i = 0; i < garages; i++) {
        scanf("%d %d %d %d", &garNum, &s, &k, &th);

        // Ensure garNum is within bounds (1-10)
        if (garNum >= 1 && garNum <= 10) {
            initQueue(&q[garNum], garNum, k, th, s);
            createReverseCircle(&q[garNum]);
        } else {
            printf("Error: Garage number %d is out of bounds (1-10). Please provide a valid garage number.\n", garNum);
            return 1; // Exit if an invalid garage number is encountered
        }
    }

    // Prints the initial status of the queues
    printf("Initial status of nonempty queues\n");
    for (int i = 1; i <= 10; i++) {  // Start from 1
        display(&q[i]);
    }

    // Rearrange the circle
    for (int i = 1; i <= 10; i++) {  // Start from 1
        rearrangeCircle(&q[i]);
    }

    printf("\nAfter ordering status of nonempty queues\n");
    for (int i = 1; i <= 10; i++) {  // Start from 1
        display(&q[i]);
    }

    // Phase 1 elimination
    printf("\nPhase1 elimination\n");
    for (int i = 1; i <= 10; i++) {  // Start from 1
        phase1(&q[i]);
    }

    // Phase 2 elimination
    printf("\nPhase2 elimination\n");
    phase2(q);
    return 0;
}

