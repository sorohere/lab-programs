#include "apue.h"
#include <dirent.h>
#include <stdio.h>

int main (int argc, char *argv[]){
        DIR *dp;
        struct dirent *dirp;

        if (argc != 2) printf("usage: is dir_name");
        if((dp = opendir(argv[1])) == NULL) printf("cant open.");

        while((dirp = readdir(dp)) != NULL) printf("%s\n", dirp-> d_name);

        closedir(dp);
        exit(0);

}
