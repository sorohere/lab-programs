#include <stdio.h>
#include <string.h>

char stk[50];
int top = -1;

char pop(){
    return stk[top--];
}

void push(char ch){
    stk[++top] = ch;
}

char topp(){
    return stk[top];
}

int isempty(){
    if(top == -1) return 1;
    else return 0;
}

int prec(char ch){
    switch(ch){
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

int solve(char* infix, char* ans){
    int n = strlen(infix);
    int pointer = 0;
    char temp;
    
    for(int i = 0; i < n; i++){
        char curr = infix[i];
        switch(curr){
            case '(':
                push(curr);
                break;
            case ')':
                while((temp = pop()) != '('){
                    ans[pointer++] = temp;
                }
                break;
            case '+':
            case '-':
            case '/':
            case '*':
                while(!isempty() && prec(topp()) >= prec(curr)){
                    ans[pointer++] = pop();
                }
                push(curr);
                break;
            default:
                ans[pointer++] = curr;
        }
    }
    while(!isempty()){
        ans[pointer++] = pop();
    }
    ans[pointer] = '\n';
    return pointer;
}

void print(char* ans, int n){
    for(int i = 0; i < n; i++){
        printf("%c ", ans[i]);
    }
}

int main() {
    
    char infix[100];
    char ans[100];
    
    scanf("%s", infix);
    int n = solve(infix, ans);
    
    print(ans, n);

    return 0;
}
