#include <stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>

#define BUFFSIZE 512

void myread(char cary[]){

	printf("cary = %d\n", cary);
	cary[0] = 'a';
	cary[1] = 'b';
}

int main(int argc,char **argv){

	/*printf("argc=  %d\n",argc);
	printf("argv[0] = %s\n",argv[0]);
	printf("argv[1] = %s\n",argv[1]);
	printf("argv[2] = %s\n",argv[2]);*/

	for(int i = 0; i<argc; i++){
		printf("arg[%d] = %s\n",i,argv[i]);
	}


	char buf[BUFFSIZE];
//	printf("buf = %d\n",buf);
//	myread(buf);
//	printf("buf[0] = %c buf[1] = %c\n",buf[0],buf[1]);

	ssize_t nread;	
	int fd = open("myfile",O_RDONLY);

	if(fd == -1){
		printf("file open fail\n");
	}
	while((nread = read(fd,buf,BUFFSIZE)) > 0) {
		printf("buf = %s\n",buf);
	}

	return 0;
}


