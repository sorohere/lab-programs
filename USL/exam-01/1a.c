#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        exit(1);
    }

    off_t file_size = lseek(fd, 0, SEEK_END);
    if (file_size == -1) {
        perror("Error determining file size");
        close(fd);
        exit(1);
    }

    char ch;
    for (off_t i = file_size - 1; i >= 0; i--) {
        if (lseek(fd, i, SEEK_SET) == -1) {
            perror("Error seeking in file");
            close(fd);
            exit(1);
        }

        if (read(fd, &ch, 1) != 1) {
            perror("Error reading file");
            close(fd);
            exit(1);
        }

        putchar(ch);
    }

    close(fd);
    putchar('\n');
    exit(0);
}


// ./a.out t1.txt t2.txt
