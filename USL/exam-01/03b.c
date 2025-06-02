// Write a C program to implement ls  –li command which lists the files in a specified 
// directory. Your program should Print 5 attributes of files.

// 2a + 3a

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<time.h>
#include<sys/stat.h>

int main(int arg, char* argv[])
{
        struct dirent *dir;
        struct stat s;
        DIR *dp;

        dp = opendir(".");

        printf("--inode--mode-- uid--guid--access_time--Filename\n");
        while(dir = readdir(dp)){
                stat(dir->d_name,&s);
                printf("%llu %o %d %d %s %s\n", s.st_ino, s.st_mode, s.st_uid, s.st_gid, ctime(&s.st_atime), dir->d_name);
        }
        
}

// ./a.out 
