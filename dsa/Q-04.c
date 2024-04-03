#include <stdio.h>
#include <string.h>

int stk[50];
int top = -1;

int pop(){
    return stk[top--];
}

int push(int ch){
    stk[++top] = ch;
}

int topp(){
    return stk[top];
}

int isempty(){
    if(top == -1) return 1;
    else return 0;
}

float solve(char* string){
    int m = strlen(string);
    
    for(int i = 0; i < m; i++){
        char curr = string[i];
        
        if(curr >= '0' && curr <= '9') push(curr-'0');
        else{
            int a = pop();
            int b = pop();
            
            switch(curr){
                case '+':
                    push(b+a);
                    break;
                case '-':
                    push(b-a);
                    break;
                case '*':
                    push(b*a);
                    break;
                case '/':
                    push(b/a);
                    break;
            }
        }
    }
    return topp();
}

int main() {
    
    char string[100];
    scanf("%s", string);
    
    int ans = solve(string);
    printf("%d", ans);

    return 0;
}
