// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node* left;
    struct Node* right;
} node;

node* create(int key){
    node* temp = (node*)malloc(sizeof(node));
    temp->value = key;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

node* insert(node* head, int key){
    if(head == NULL) return create(key);
    else if(head-> value > key) head->left = insert(head->left, key);
    else if(head-> value < key) head->right = insert(head->right, key);
    return head;
}


void post(node* head){
    node* temp = head;
    if(temp != NULL){
        post(head->left);
        post(head->right);
        printf("%d ",temp->value);
    }
}

void pre(node* head){
    node* temp = head;
    if(temp != NULL){
        printf("%d ",temp->value);
        pre(head->left);
        pre(head->right);
    }
}

void in(node* head){
    if(head != NULL){
        in(head->left);
        printf("%d ",head->value);
        in(head->right);
    }
}


int main() {
   node* head = NULL;
   
   head = insert(head, 20);
   head = insert(head, 10);
   head = insert(head, 30);
   head = insert(head, 5);
   head = insert(head, 15);
   head = insert(head, 25);
   head = insert(head, 35);
   
   pre(head);
   
    return 0;
}
