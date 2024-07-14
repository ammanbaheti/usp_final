#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc,char* argv[]){
	int fd;
	char buf[100];

	if((fd=open(argv[1],O_RDWR))<0){
		 fprintf(stderr,"Failed to open File\n");
                exit(-1);
        }
	int pid = fork();

	if(pid<0){
		 printf("Child PRocess Failed\n");
                exit(-1);
        }
	else if(pid==0){
		int size = read(fd,&buf,5);
		if(size<0){
			printf("Child Failed to read\n");
			exit(-1);
		}
		buf[size]='\0';
		printf("Child Read: %s \n",buf);
		close(fd);
	}
	else{
		wait(NULL);
		int size = read(fd,&buf,5);
                if(size<0){
                        printf("Parent Failed to read\n");
                        exit(-1);
                }
                buf[size]='\0';                             
		printf("Parent Read: %s \n",buf);                                                                                                    close(fd);
	
	}
}	
