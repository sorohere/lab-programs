#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s num1 num2\n", argv[0]);
        exit(0);
    }
    
    pid_t pid = fork();
    
    if (pid < 0) {
        perror("fork failed");
        exit(0);
    } else if (pid == 0) {  // Child process
        // Execute the p23 program with the two numbers as arguments
        execl("./p2", "p2", argv[1], argv[2], (char *)NULL);
        
        // If execl fails
        perror("execl failed");
        exit(EXIT_FAILURE);
    } else {  // Parent process
        int status; 
        waitpid(pid, &status, 0);  // Wait for the child process to finish
        
        if (WIFEXITED(status)) {
            printf("Child exited with status %d\n", WEXITSTATUS(status));
        } else {
            printf("Child terminated abnormally\n");
        }
    }
    
    return 0;
}


// cc -o main_program main_program.c
// cc -o p23 p23.c
// ./main_program 5 6
