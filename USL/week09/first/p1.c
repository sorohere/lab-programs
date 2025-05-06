#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

int main() {
    pid_t pid;
    int status;
    pid_t parent_pid = getpid();

    pid = fork();  // Create a child process

    if (pid == -1) {  // Handle fork failure
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {  // Child process
        pid_t child_pid = getpid();
        printf("Child process (PID: %d) executing...\n", child_pid);

        // Execute the p1 program to check file access
        execl("./p2", "p2", "example.txt", (char *)NULL);

        // If execl fails
        perror("execl");
        exit(EXIT_FAILURE);
    } else {  // Parent process
        printf("Parent process (PID: %d) executing...\n", parent_pid);

        // Wait for the child process to exit
        waitpid(pid, &status, 0);
        printf("Parent process: Child process (PID: %d) has exited.\n", pid);
    }

    return 0;
}

// cc -o p2 p2.c 
// cc p1.c
// ./a.out  # Run the main program
