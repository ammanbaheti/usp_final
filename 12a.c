#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<fcntl.h> 
#include <sys/wait.h> 
int main(void) { 
    pid_t pid,pid2,pid3;
   if((pid=fork())<0){
	  perror("Fork Failed");
	  exit(EXIT_FAILURE);
        }
   else if(pid==0){
	  if((pid3=fork())<0){
		  perror("Fork Failed");
          exit(EXIT_FAILURE);
        }
	  else if(pid3==0){
		 sleep(5);
		printf("Second Child: %ld\n",(long)getpid());
	       printf("Second Child's parent: %ld\n",(long)getppid());
	  	 exit(0);
	  }
	  else{
	printf("First Child: %ld\n",(long)getpid());
	 exit(0);
	  }	
   }
   int status;
   if((pid2=waitpid(pid,&status,0))!=pid)
	   perror("Termination Error");

   printf("terminated Child's PID: %ld\n",(long)pid2);
    exit(0);

}
