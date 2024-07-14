#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/wait.h> 
#include<sys/types.h>

int main(){
	pid_t pid1,pid2;
	pid1=fork();
	pid2=fork();
int st;
	if(pid1==0){
		printf("CHild 1 with pid : %d\n",getpid());
		sleep(2);
		exit(0);
	}
	if(pid2==0){
                printf("CHild 2 with pid : %d\n",getpid());
                sleep(3);
                exit(0);
        }

	wait(&st);
	printf("First wait: Parent process PID = %d has completed waiting for one child process(pid: %d)\n", getpid(),pid1);
	sleep(1);
	waitpid(pid2,&st,0);
	printf("Second wait: Parent process PID = %d has completed waiting for other child process(pid:%d)\n", getpid(),pid2);
	return 0;
}

