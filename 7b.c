#include <stdio.h>
#include<stdlib.h>
#include <fcntl.h> 
#include <unistd.h> 
#define BUFFER_SIZE 1024

int main(int argc,char * argv[]){
	if(argc<3){
		perror("Source dest");
		exit(EXIT_FAILURE);
	}

	int src= open(argv[1],O_RDWR);
	int dest = open(argv[2],O_CREAT|O_TRUNC|O_RDWR,0644);
	//hANDLE ERROR IN FINAL EXAM
	int bytes_read;
	char buf[1024];
	while((bytes_read=read(src,buf,1024))>0){
		if(write(dest ,buf,bytes_read)!=bytes_read){
			perror("Write");
			exit(EXIT_FAILURE);
		}
	}
	if(bytes_read<0){
		perror("ERROR");
		return 1;
	}
	close(src);
	close(dest);
	return 0;
}
	
