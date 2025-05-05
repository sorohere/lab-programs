// Demonstrate the working of wait and waitpid system calls with a program

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    int status;
    pid_t pid = fork();

    if (pid == 0) {
        printf("Child 1 (PID %d)\n", getpid());
        sleep(2);
        exit(0);
    }

    pid_t pid2 = fork();
    if (pid2 == 0) {
        printf("Child 2 (PID %d)\n", getpid());
        sleep(4);
        exit(0);
    }

    wait(&status);
    printf("One child finished\n");

    waitpid(pid2, &status, 0);
    printf("Second child finished\n");

    return 0;
}
