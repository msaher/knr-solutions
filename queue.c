// #define MAXQ 10000
#include <stdio.h>

/* static char* queue[MAXQ] */
static int front = -1; /* index of the front of the queue */
static int rear = -1; /* index of the rear of the queue */
static unsigned int numptr = 0;
/* static int size = MAXQ; */


void nq(char* ptr, char** q, int size);
char* dq(char **q, int size);

char* dq(char **q, int size) {
    if(front == -1) {
        fprintf(stderr, "Error: Attempting to dequeue an empty queue\n");
        return NULL;
    }

    char* ptr = q[front]; 

    if(front == rear)
        front = rear = -1;
    else
        front = (front + 1) % size;
    numptr--;

    return ptr;
}

void nq(char* ptr, char** q, int size) {
    if(front == -1) { // empty
        front = rear = 0;
        numptr++;
        q[front] = ptr;
        return;
    }
    /* Make room by dequeueing */
    else if(numptr == size)
        dq(q, size);

    rear = (rear + 1) % size;
    q[rear] = ptr;
    numptr++;
}
