#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    struct stat buf;
    char *type;
    
    for (int i = 1; i < argc; i++) {
        lstat(argv[i], &buf);
        type = (S_ISREG(buf.st_mode)) ? "regular" :
               (S_ISDIR(buf.st_mode)) ? "directory" :
               (S_ISCHR(buf.st_mode)) ? "character special" :
               (S_ISBLK(buf.st_mode)) ? "block special" :
               (S_ISFIFO(buf.st_mode)) ? "fifo" :
               (S_ISLNK(buf.st_mode)) ? "symbolic link" :
               (S_ISSOCK(buf.st_mode)) ? "socket" : "** unknown mode **";
        printf("%s: %s\n", argv[i], type);
    }
    return 0;
}
