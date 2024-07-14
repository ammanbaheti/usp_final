#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/wait.h> 
void err_sys(const char *message) { 
    perror(message); 
    exit(1); 
} 
int main(void) { 
	pid_t pid;
	char * envp[]={"User=Unknown","path=/tmp",NULL};
	if((pid=fork())<0){
		err_sys("fork failed");
	}
	else if(pid==0){
		if(execle("/home/ammanb03/usp_final/12echoall","echoall","arg1","arg2",(char*)NULL,envp)<0){
			err_sys("Execle");
		}
	}
	   if (waitpid(pid, NULL, 0) < 0) {
        err_sys("wait error");
    }
	if(execlp("/home/ammanb03/usp_final/12echoall","echoall","arg1","arg2",(char*)NULL)<0){
		err_sys("Execlp");
        }
	return 0;
}
