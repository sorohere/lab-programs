// Write a C program to demonstrate the usage of umask and chmod functions.

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    umask(0);
    creat("foo", 0644); 
    umask(022);
    creat("bar", 0666);

    return 0;
}


int main() {
    chmod("foo", 0777);  
    chmod("bar", 0600); 
    
    return 0;
}
