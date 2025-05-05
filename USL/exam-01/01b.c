#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>

int main(int c, char **v) {
    int f = open(v[1], 0);
    char b[6];
    if (!fork()) {
        read(f, b, 5); 
        b[5] = 0;
        printf("Child: %s\n", b);
    } 
    else {
        wait(0);
        read(f, b, 5); 
        b[5] = 0;
        printf("Parent: %s\n", b);
    }
}
