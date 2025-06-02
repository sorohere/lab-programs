#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int fd = open(argv[1], O_RDWR);
    struct flock lock;

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_END;
    lock.l_start = -100;
    lock.l_len = 100;

    fcntl(fd, F_SETLK, &lock);  // Lock last 100 bytes

    printf("Locked last 100 bytes. Press Enter to release lock...\n");
    getchar();  // Wait for user input to release lock

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);  // Unlock

    close(fd);
    return 0;
}
