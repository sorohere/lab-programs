// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

int arr[100];
int size = 0;
int capacity = 10;

int left(int i){ return 2*i + 1; }
int right(int i){ return 2*i + 2; }
int parent(int i){ return (i-1)/2; }

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print() {
    for(int i = 0; i < size; i++){
        printf("%d ",arr[i]);
    }
}

void insert(int key){
    if(size == capacity) {
        printf("overflow.");
        return;
    }
    size++;
    arr[size-1] = key;
    
    for(int i = size-1; i != 0 && arr[i] > arr[parent(i)];){
        swap(&arr[i], &arr[parent(i)]);
        i = parent(i);
    }
}

void heapify(int i){
    int r = right(i);
    int l = left(i);
    int greatest = i;
    
    if(r < size && arr[i] < arr[r]) greatest = r;
    if(l < size && arr[l] > arr[greatest]) greatest = l;
    
    if(greatest != i){
        swap(&arr[i], &arr[greatest]);
        heapify(greatest);
    }
}

void pop(){
    if(size == 0){
        printf("underflow");
        return;
    }
    swap(&arr[0], &arr[size-1]);
    size--;
    heapify(0);
}

int main() {
    insert(30);
    insert(40);
    insert(10);
    insert(21);
    pop();
    pop();
    pop();
    pop();
    pop();
    pop();
    
    print(0, 0);
   
    return 0;
}
