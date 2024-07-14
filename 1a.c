#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>

int main(int argc,char *argv[]){
	char buf;
	int fd;

	if(argc<2){
		fprintf(stderr,"Usage: %s <filname>\n",argv[0]);
		exit(-1);
	}
	
	if((fd=open(argv[1],O_RDONLY))<0){
		 fprintf(stderr,"Error Opening the file\n");
                exit(-1);
        }

	int size = lseek(fd,(off_t)0,SEEK_END);

	for(int i=size-1;i>=0;i--){
		lseek(fd,(off_t)i,SEEK_SET);
		read(fd,&buf,1);
		printf("%c",buf);
	}
	printf("\n");
	close(fd);
	return 0;
}


