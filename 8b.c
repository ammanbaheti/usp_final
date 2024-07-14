#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<errno.h>
#include<unistd.h>

int main(){
	int ppid = getpid();
	int st;


	int pid= fork();

	if(pid<0){
		perror("Fork Failed\n");
		exit(EXIT_FAILURE);
	}else if(pid==0){
		printf("CHild Process is executiong with pid: %d\n :",pid);
		if(access("8btest.txt",F_OK)==0){
			printf("FileExists and can be accessed \n");
		}
		else{
			printf("File cannot be accessed or it does not exiust\n");
		}
		exit(EXIT_SUCCESS);
	}
	else{
		waitpid(pid,&st,0);
		ppid= getpid();
		printf("Child Finished Ececuting\n");
		printf("Parebt(PID: %d) process executed...\n",ppid);
	}
	return 0;
}
		

