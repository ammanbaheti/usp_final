#include <stdio.h> 
#include <unistd.h> 
#include <fcntl.h> 
#include <sys/types.h> 
#include <sys/stat.h> 

#include <stdlib.h> 

int main(int argc,char* argv[]){
	char* ptr;
	struct stat st;
	for(int i=1;i<argc;i++){
		printf("%s: ",argv[i]);
		if(lstat(argv[i],&st)<0){
			perror("File Open:");
			return 1;
		}
		if(S_ISREG(st.st_mode))
			ptr = "Regualr file";
		else if(S_ISLNK(st.st_mode))
			ptr="SYMLINK";
		else if(S_ISFIFO(st.st_mode))
                        ptr="fifo";
		else if(S_ISCHR(st.st_mode))
                        ptr="CHARACTER";
		else if(S_ISSOCK(st.st_mode))
                        ptr="SOCKET";
		else if(S_ISBLK(st.st_mode))
                        ptr="BLOCK";
		else if(S_ISDIR(st.st_mode))
                        ptr="DIRECTORY";
		else
			ptr="UNKONWN";
	printf("%s\n",ptr);
	}
	exit(0);
}
