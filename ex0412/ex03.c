#include <stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>

#define BUFFSIZE 512

int main(int argc, char **argv){
    
    char buf[BUFFSIZE];
    size_t nread;

    // file1
    int fd1 = open(argv[1], O_RDONLY);
    if(fd1 == -1){
        perror("fd1 file open faile");
    }

    //file2
    int fd2 = open(argv[2],O_WRONLY|O_CREAT,0777);
    if(fd1 == -1){
        perror("fd1 file open faile");
    }
    
    while((nread = read(fd1,buf,BUFFSIZE)) > 0){
        write(fd2,buf,nread);
    }
}