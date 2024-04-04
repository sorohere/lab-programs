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

node* insertf(node* head, int key){
    node* temp = create(key);
    if(head == NULL) {
        return temp;
    }
    temp-> right = head;
    head-> left = temp;
    return temp;
}

node* inserte(node* head, int key){
    node* temp = create(key);
    if(head == NULL) {
        return temp;
    }
    
    node* curr = head;
    while(curr-> right != NULL){
        curr = curr->right;
    }
    
    curr-> right = temp;
    temp-> left = curr;
    return head;
}

node* insertp(node* head, int key, int pos){
    if(head == NULL) return insertf(head, key);
    
    node* curr = head;
    for(int i = 0; i < pos-1; i++){
        if(curr-> right != NULL) curr = curr->right;
    }
    
    if(curr-> right == NULL) return inserte(head, key);
    
    node* temp = create(key);
    
    curr-> left-> right = temp;
    temp->left = curr-> left;
    temp->right = curr;
    return head;
}

node* popf(node* head){
    if(head == NULL) return NULL;
    if(head ->right == NULL) {
        free(head);
        return NULL;
    }
    
    node* temp = head;
    head = head->right;
    free(temp);
    return head;
}

node* pope(node* head){
    if(head == NULL) return NULL;
    if(head ->right == NULL) {
        free(head);
        return NULL;
    }
    node* temp = head;
    while(temp-> right != NULL){
        temp = temp->right;
    }
    temp->left->right = NULL;
    free(temp);
    return head;
}

node* popp(node* head, int pos){
    
    if(head == NULL) return NULL;
    
    if(pos == 1) return popf(head);
    
    node* curr = head;
    for(int i = 0; i < pos-1; i++){
        curr = curr->right;
    }
    
    if(curr-> right == NULL) return pope(head);
    
        
    node* prev = curr-> left;
    node* next = curr-> right;
    
    prev-> right = next;
        
    // free(curr);
    
    return head;
}

void display(node* head){
    node* temp = head;
    while(temp != NULL){
        printf("%d ", temp->value);
        temp = temp->right;
    }
    printf("\n");
}


int main() {
   node* head = NULL;
   
   head = insertf(head, 1);
   head = inserte(head, 2);
   head = insertf(head, 3);
   head = insertf(head, 4);
   head = insertf(head, 1);
   head = insertf(head, 2);
   
   head = popp(head, 2);
   
   display(head);
    return 0;
}
