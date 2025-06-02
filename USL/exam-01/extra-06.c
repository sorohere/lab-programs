// Write a program to demonstrate the zombie state of a process and provide the solution for the same. 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("Child process (PID: %d) exiting\n", getpid());
        exit(0);
    } 
    else {
        wait(NULL);  // <-- Solution: Clean up the child process
        printf("Parent process (PID: %d) sleeping\n", getpid());
        sleep(30);
        printf("Parent exiting\n");
    }

    return 0;
}

// ./a.out
// ps aux | grep Z
