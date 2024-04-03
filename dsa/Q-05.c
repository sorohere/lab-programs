#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int *arr;
    int rear, front;
    int size;
    int capacity;
} queue;

queue* init(int size) {
    queue* q = (queue*)malloc(sizeof(queue));
    q->arr = (int*)malloc(size * sizeof(int));
    q->size = 0;
    q->front = -1;
    q->rear = -1;
    q->capacity = size;

    return q;
}

void insert(queue* q, int key) {
    if (q->size == q->capacity) return;
    q->rear = (q->rear + 1) % q->capacity;
    q->arr[q->rear] = key;
    q->size++;
}

void pop(queue* q) {
    if (q->size == 0) return;
    q->front = (q->front + 1) % q->capacity;
    int element = q->arr[q->front];
    q->size--;
    printf("popped : %d\n", element);
}

void display(queue* q) {
    for (int i = q->front + 1; i < q->front + q->size + 1; i++) {
        printf("%d ", q->arr[i % q->capacity]);
    }
    printf("\n");
}

int main() {
    queue* q = init(5);

    insert(q, 2);
    insert(q, 3);
    insert(q, 5);
    display(q);
    insert(q, 9);
    insert(q, 8);
    display(q);

    pop(q);
    pop(q);

    display(q);

    return 0;
}
