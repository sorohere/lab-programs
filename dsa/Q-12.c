// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

#define max 100

typedef struct Node{
    int value;
    struct Node* next;
} node;

typedef struct Graph{
    int maxnodes;
    node* adjlst[max];
} graph;

node* createnode(int key){
    node* temp = (node*)malloc(sizeof(node));
    temp->next = NULL;
    temp->value = key;
    
    return temp;
}

graph* creategraph(){
    graph* temp = (graph*)malloc(sizeof(graph));
    temp->maxnodes = max;
    return temp;
}

node* push(node* head, node* temp){
    if(head == NULL) return temp;
    node* curr = head;
    while(curr->next != NULL){
        curr = curr-> next;
    }
    curr->next = temp;
    return head;
}

void addedge(graph* g, int src, int des){
    node* temp = createnode(des);
    g->adjlst[src] = push(g->adjlst[src], temp);
    
    temp = createnode(src);
    g->adjlst[des] = push(g->adjlst[des], temp);
}

void bfs(graph* g, int start){
    int *visited = (int*)malloc(max*sizeof(int));
    for(int i = 0; i < max; i++){
        visited[i] = 0;
    }
    int queue[max];
    int rear = 0;
    int front = 0;
    
    queue[rear++] = start;
    visited[start] = 1;
    
    while(front < rear){
        int curr = queue[front++];
        printf("%d ", curr);
        node* temp = g->adjlst[curr];
        while(temp != NULL){
            int element = temp->value;
            if(!visited[element]){
                queue[rear++] = element;
                visited[element] = 1;
            }
            temp = temp->next;
        }
    }
}

void solve(graph* g, int* visited, int start){
    visited[start] = 1;
    printf("%d ",start);
    
    node* temp = g->adjlst[start];
    while(temp != NULL){
        int curr = temp->value;
        if(!visited[curr]){
            solve(g, visited, curr);
        }
        temp=temp->next;
    }

}

void dfs(graph* g, int start){
    int *visited = (int*)malloc(max*sizeof(int));
    for(int i = 0; i < max; i++){
        visited[i] = 0;
    }
    solve(g, visited, start);
}

int main() {
    graph* g = creategraph();
    
    addedge(g, 0, 1);
    addedge(g, 0, 2);
    addedge(g, 1, 3);
    addedge(g, 1, 4);
    addedge(g, 2, 5);
    addedge(g, 2, 6);
    bfs(g,0);
    // addedge(g, 0, 1);

    return 0;
}
