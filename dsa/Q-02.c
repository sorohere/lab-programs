#include <stdio.h>
#include <string.h>

int nfind(char* string, char* pattern){
    int m = strlen(string)-1;
    int n = strlen(pattern)-1;
    
    int start = 0;
    int end = n;
    
    int j = 0;
    
    for(int i = 0; end <= m; start++, end++){
        if(string[end] == pattern[n]){
            for(i = start,j = 0; j <= n && string[i] == pattern[j]; i++, j++);
            if(j == n+1) printf("index : %d\n", start);
        }
    }
    if(end == m) printf("not found.");
}

void solve(char* pattern, int* arr, int n){
    arr[0] = 0;
    int start = 0;
    int i = 1;
    
    while (i < n) {
        if(pattern[start] == pattern[i]) arr[i++] = ++start;
        else {
            if(start != 0) start = arr[start-1];
            else arr[i++] = 0;
        }
    }
}

void kmp(char* string, char* pattern){
    int n = strlen(string);
    int m = strlen(pattern);
    int arr[m];
    
    solve(pattern, arr, m);
    
    int i = 0;
    int j = 0;
    
    while(i < n){
        if (string[i] == pattern[j]){
            i++; 
            j++;
        }
        if(j == m){
            printf("pattern fount at index : %d\n", i-j);
            j = arr[j-1];
        }
        else if(i < n && string[i] != pattern[j]){
            if(j != 0) j = arr[j-1];
            else i++;
        }
    }
}


int main() {
    
    char text[1000];
    scanf("%s", text);

    char pattern[1000];
    scanf("%s", pattern);

    kmp(text, pattern);

    return 0;
}
