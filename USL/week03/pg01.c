#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    int fd1 = 0, fd2 = 0;
    char buf[10] = "abcdef";

    printf("%d %d \n", fd1, fd2);

    if ((fd1 = open("sample.txt", O_RDWR, 0)) < 0) {
        printf("error\n");
        return 1;
    }

    fd2 = dup(fd1);

    write(fd1, buf, 6);

    return 0;
}
