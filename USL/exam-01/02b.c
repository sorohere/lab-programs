// Write a C program to simulate system function.

#include <unistd.h>
#include <sys/wait.h>

int my_system(const char *cmd) {
    if (fork() == 0)
        execl("/bin/sh", "sh", "-c", cmd, NULL);
    int status;
    wait(&status);
    return status;
}

int main() {
    my_system("ls -l");
    return 0;
}

// ./a.out test.txt