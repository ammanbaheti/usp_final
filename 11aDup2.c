#include <stdio.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
int main() { 
    int fd11 = 0, fd12 = 0;
    fd11 = open("11atest.txt",O_RDWR|O_CREAT,0);
    char buf[20]="abcdef";
    dup2(fd12,fd11);

      printf("Process Descriptors: %d %d \n", fd11, fd12);
    write(fd11, "teri maa ki....\n", 17);
    return 0;
}
