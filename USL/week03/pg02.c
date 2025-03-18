#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    int fd11 = 0, fd12 = 0;
    char buf[10] = "abcdef";

    if ((fd12 = open("t12.txt", O_RDWR, 0)) < 0) {
        printf("error\n");
        return 1;
    }

    if (dup2(fd12, fd11) < 0) {
        printf("error\n");
        return 1;
    }

    printf("%d %d\n", fd11, fd12);
    write(fd11, buf, 6);

    return 0;
}
