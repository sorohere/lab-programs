// Write a C program to demonstrate the creation of soft links and  hard links.

#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) 
{
    if (argc == 3) {
        link(argv[1], argv[2]);  
        printf("Hard link created.\n");
    } 
    else if (argc == 4) {
        symlink(argv[1], argv[2]);  
        printf("Soft link created.\n");
    }

    return 0;
}

// ./a.out test.txt test2.txt
// ./a.out test.txt test2.txt 1