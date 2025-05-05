// Write a C program to display various details of a file using stat structure (At least 5 fields).

#include <sys/stat.h>
#include <stdio.h>

int main(int c, char **v) {
    struct stat s;
    stat(v[1], &s);

    printf("File Name: %s\n", v[1]);
    printf("Size: %lld\n", s.st_size);
    printf("Links: %hu\n", s.st_nlink);
    printf("Inode: %llu\n", s.st_ino);
    printf("Perms: %o\n", s.st_mode & 0777);
    printf("Is symlink: %d\n", S_ISLNK(s.st_mode));
}

// ./a.out test.txt