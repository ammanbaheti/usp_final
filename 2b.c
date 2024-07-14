#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int main(int argc,char * argv[]){
	if(argc<2){
		perror("Source Usage");
		exit(EXIT_FAILURE);
	}
	int pid = fork();

	if(pid<0){
		perror("Fork Failed");
		 exit(EXIT_FAILURE);
        }
	else if(pid==0){
		execl("/bin/sh","sh","-c",argv[1],NULL);
		_exit(EXIT_FAILURE);
	}
	else{ int status;
		if(waitpid(pid,&status,0)==-1){
			printf("ERROR");
			exit(EXIT_FAILURE);
		}
		else{
			printf("Command Ececuted\n");
		}
	} return 0;
}

