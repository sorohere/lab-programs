#include <stdio.h>
#include <stdlib.h>

#define max 100

typedef struct Sparce{
    int row;
    int col;
    int value;
} sp;

void read(sp sp[]){
    for(int i = 1; i <= sp[0].value; i++){
        scanf("%d", &sp[i].row);
        scanf("%d", &sp[i].col);
        scanf("%d", &sp[i].value);
    }
}

void display(sp sp[]){
    for(int i = 0; i <= sp[0].value; i++){
        printf("%d", sp[i].row);
        printf("%d", sp[i].col);
        printf("%d\n", sp[i].value);
    }
}

void solvefast(sp sp1[], sp sp2[]){
    sp2[0].row = sp1[0].col;
    sp2[0].col = sp1[0].row;
    sp2[0].value = sp1[0].value;
    
    int arr1[sp1[0].col];
    int arr2[sp1[0].col];
    
    for(int i = 0; i < sp1[0].col; i++){
        arr1[i] = 0;
    }

    for(int i = 1; i <= sp1[0].value; i++){
        arr1[sp1[i].col]++;
    }
    
    arr2[0] = 1;
    for(int i = 1; i < sp1[0].col; i++){
        arr2[i] = arr2[i-1] + arr1[i-1];
    }
    
    for(int i = 1; i <= sp1[0].value; i++){
        int curr = sp1[i].col;
        int index = arr2[curr]++;
                sp2[index].row = sp1[i].col;
                sp2[index].col = sp1[i].row;
                sp2[index].value = sp1[i].value;
    }
}

void solve(sp sp1[], sp sp2[]){
    sp2[0].row = sp1[0].col;
    sp2[0].col = sp1[0].row;
    sp2[0].value = sp1[0].value;
    
    int pointer = 1;
    for(int i = 0; i < sp1[0].col; i++){
        for(int j = 1; j <= sp1[0].value; j++){
            if(sp1[j].col == i){
                sp2[pointer].row = sp1[j].col;
                sp2[pointer].col = sp1[j].row;
                sp2[pointer++].value = sp1[j].value;
            }
        }
    }
}

int main() {
    
    sp sp1[max];
    sp sp2[max];
    
    scanf("%d", &sp1[0].row);
    scanf("%d", &sp1[0].col);
    scanf("%d", &sp1[0].value);
    
    read(sp1);
    // display(sp1);
    solvefast(sp1, sp2);
    display(sp2);

    return 0;
}
