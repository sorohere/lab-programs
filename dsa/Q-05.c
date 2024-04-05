#include <stdio.h>
#include <stdlib.h>

int* arr;
int size;
int capacity;
int rear;
int front;

void init(int cap){
    arr = (int*)malloc(cap*sizeof(int));
    size = 0;
    capacity = cap;
    rear = -1;
    front = -1;
}

void enqueue(int key){
    if(size == capacity){
        printf("overflow.\n");
        capacity *= 2;
        int* temp = (int*)malloc(capacity*sizeof(int));
        int j = 0;
        for(int i = front+1; i < front+1 + capacity/2; i++){
            temp[j++] = arr[i%(capacity/2)];
        }
        
        front = -1;
        rear = size-1;
        int* dummy = arr;
        free(dummy);
        arr = temp;
    }
    rear = (rear+1)%capacity;
    arr[rear] = key;
    size++;
}

void dequeue(){
    if(size == 0){
        printf("empty.\n");
        return;
    }
    front = (front+1)%capacity;
    size--;
    printf("%d : popped\n", arr[front]);
}

void display(){
    for(int i = front+1; i < front+1 + size; i++){
        printf("%d ", arr[i%(capacity)]);
    }
}

int main(){
    init(5);

    enqueue(0);
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    dequeue();
    dequeue();
    enqueue(5);
    enqueue(6);
    enqueue(7);
    enqueue(8);
    enqueue(9);
    enqueue(4);
    dequeue();
    enqueue(1);
    enqueue(6);
    enqueue(7);
    
    display();
    
    return 0;
}
