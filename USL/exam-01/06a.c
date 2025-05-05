// Write a C program to demonstrate the usage of umask and chmod functions.

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    umask(0);
    creat("demo.txt", 0666);  // rw-rw-rw-
    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main() {
    chmod("demo.txt", 0777); // rwx------
    return 0;
}

