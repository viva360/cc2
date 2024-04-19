#include <stdio.h>
#include <stdbool.h>

#define MAX_CAPACITY 5

typedef struct Queue {
    int queue[MAX_CAPACITY];
    int front;
    int rear;
    int size;
} Queue;
void initializeQueue(Queue* q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}
// check Q is empty
bool is_empty(Queue* q) {
    return q->size == 0;
}
// check Q is full
bool is_full(Queue* q) {
    return q->size == MAX_CAPACITY;
} 
// insertion in Q
void enqueue(Queue* q, int item) {
    if (is_full(q)) {
        printf("Queue is full. Cannot enqueue more elements.\n");
    } else {
        q->rear = (q->rear + 1) % MAX_CAPACITY;
        q->queue[q->rear] = item;
        q->size++;	
    }
}

// deletion in Q
int dequeue(Queue* q) {
    if (is_empty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; 
    } else {
        int front_element = q->queue[q->front];
        q->front = (q->front + 1) % MAX_CAPACITY; //circular queue formula
        q->size--;
        return front_element;
    }
}

// return the front element(peek)
int front(Queue* q) {
    if (is_empty(q)) {
        printf("Queue is empty.\n");
        return -1;
    } else {
        return q->queue[q->front];
    }
}

int rear(Queue* q) {
    if (is_empty(q)) {
        printf("Queue is empty.\n");
        return -1;
    } else {
        return q->queue[q->rear];
    }
}

void print_queue(Queue* q) {
    if (is_empty(q)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue: ");
        int i;
        for (i = 0; i < q->size; i++) {
            printf("%d ", q->queue[(q->front + i) % MAX_CAPACITY]);
        }
        printf("\n");
    }
}

int main() {
    Queue queue;
    initializeQueue(&queue);

    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);
    enqueue(&queue, 4);

    print_queue(&queue); 

    printf("Dequeue: %d\n", dequeue(&queue));
    printf("After Dequeue\n");
    print_queue(&queue); 

    enqueue(&queue, 5);
    enqueue(&queue, 6);
    
    printf("Front element: %d\n",front(&queue));
    printf("Rear element: %d",rear(&queue));

    return 0;
}
