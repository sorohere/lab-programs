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

cs6c16@msritcse:~/week01$ cat pg02.c
#include "apue.h"
#define bn 4096

int main(void) {
 	int n;
        char buf[bn];

        while((n = read(STDIN_FILENO, buf, bn)) > 0){

		if(write(STDOUT_FILENO, buf, n) != n) printf("write error");
                if(n < 0) printf("read error");
                
		exit(0);
	}
}
