#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    int fd1 = 0, fd2 = 0;
    char buf[50];

    // Open the file in read-write mode
    if ((fd1 = open("sample.txt", O_RDWR, 0)) < 0) {
        printf("File open error\n");
        return 1;
    }

    // Duplicate the file descriptor
    fd2 = dup(fd1);
    printf("%d %d\n", fd1, fd2);

    // Read 10 characters from the file
    read(fd1, buf, 10);

    // Move the duplicated file descriptor to the end of the file
    lseek(fd2, 0L, SEEK_END);

    // Write the 10 characters back to the file
    write(fd2, buf, 10);

    return 0;
}
