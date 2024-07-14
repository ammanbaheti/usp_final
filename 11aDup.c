#include <stdio.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
int main() { 
    int fd1 = 0, fd2 = 0;
    char buf[20]="abcdef";
    fd1=open("11atest.txt",O_RDWR|O_CREAT);
    fd2=dup(fd1);
    printf("File Descriptor: %d %d \n",fd1,fd2);
    if(write(fd2,buf,6)<0){
	    perror("Write");
	    return -1;
    }
    return 0;
}



