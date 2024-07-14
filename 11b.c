#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <sys/wait.h>

int main(int argc,char* argv[]){
	if(argc<3){
		perror("Usage");
		exit(EXIT_FAILURE);
	}

	int pid=fork();
	if(pid<0){
		perror("Fork Failed");
		exit(EXIT_FAILURE);
	}
	else if(pid==0){
		execl("./sum","sum",argv[1],argv[2],(char*)NULL);
		perror("EXEC FAILED");
		 exit(EXIT_FAILURE);
        }
	else{int st;
		waitpid(pid,&st,0);

		if(WIFEXITED(st)){
			printf("Child Process Executed Normally with satus : %d \n",WEXITSTATUS(st));
		}else{
			printf("Child Executed Abnormally\n");
		}
	}
	return 0;
}
