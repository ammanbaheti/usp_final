#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>

void s_h(int sn){
	printf("Interrupt Caught\n");
	struct sigaction sa ;
	sa.sa_handler=SIG_DFL;
	sa.sa_flags=0;
	sigemptyset(&sa.sa_mask);
	if(sigaction(SIGINT,&sa,NULL)==-1){
		perror("SigAction");
		exit(-1);
	}
}

int main(){
	struct sigaction sa;
	sa.sa_handler=s_h;
	sa.sa_flags=0;
	sigemptyset(&sa.sa_mask);
	if(sigaction(SIGINT,&sa,NULL)==-1){
			perror("ERROR");
			exit(-1);
	}
	while(1){
		printf("Ctrl+c dabaa\n");
		sleep(1);
	}
	return 0;
}
