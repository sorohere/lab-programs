// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

#define size 6

int curr = 0;

typedef struct Node{
    int value;
    struct Node* next;
} node;

node* create(int key){
    node* temp = (node*)malloc(sizeof(node));
    temp->value = key;
    temp->next = NULL;
    
    return temp;
}

node* insert(node* head, int key){
    node* temp = create(key);
    if(curr == size) return head;
    curr++;
    if(head == NULL) return temp;
    
    temp-> next = head;
    return temp;
}

node* pop(node* head){
    if(head == NULL) return NULL;
    curr--;
    if(head ->next == NULL) return NULL;
    
    node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    node* dummy = temp->next;
    temp->next = NULL;
    free(dummy);
    return head;
}

void display(node* head){
    node* temp = head;
    while(temp != NULL){
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}


int main() {
   
   node* head = NULL;
   head = insert(head, 1);
   head = insert(head, 2);
   head = pop(head);
   head = pop(head);
   head = pop(head);
   head = pop(head);
   head = insert(head, 3);
   head = insert(head, 4);
   head = insert(head, 3);
   head = insert(head, 4);
   head = insert(head, 3);
   head = insert(head, 4);
   head = insert(head, 3);
   head = insert(head, 4);
   head = insert(head, 3);
   head = insert(head, 4);
   display(head);

    return 0;
}
