#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int source, n;
    char buf;
    int filesize;

    // Check for correct usage
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <source>\n", argv[0]);
        exit(1);
    }

    // Open the source file in read-only mode
    if ((source = open(argv[1], O_RDONLY)) < 0) {
        fprintf(stderr, "Can't open source file\n");
        exit(1);
    }

    // Get file size
    filesize = lseek(source, 0, SEEK_END);
    if (filesize < 0) {
        fprintf(stderr, "lseek failed\n");
        close(source);
        exit(1);
    }

    // Read and display file content in reverse
    for (int i = filesize - 1; i >= 0; i--) {
        lseek(source, i, SEEK_SET);
        if (read(source, &buf, 1) != 1) {
            fprintf(stderr, "Read error\n");
            close(source);
            exit(1);
        }
        write(STDOUT_FILENO, &buf, 1);
    }

    printf("\n");

    // Close the file
    close(source);

    return 0;
}
