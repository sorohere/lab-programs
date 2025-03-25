#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("\nUsage: %s <pathname>\n", argv[0]);
        exit(1);
    }

    if (access(argv[1], R_OK) < 0)
        printf("\nAccess error for %s", argv[1]);
    else
        printf("Read access OK\n\n");

    if (open(argv[1], O_RDONLY) < 0)
        printf("\nOpen error for %s\n\n", argv[1]);
    else
        printf("\nOpen for reading OK\n");

    exit(0);
}
