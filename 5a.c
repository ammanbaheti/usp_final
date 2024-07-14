#include<stdio.h> 
#include<utime.h> 
#include<fcntl.h> 
#include<unistd.h> 
#include<sys/stat.h> 
#include<stdlib.h>

int main(int argc,char *argv[]){
	struct stat fs;

	struct utimbuf new_times;
	 if(stat(argv[1],&fs)<0){
		 perror("Stat:");
		 exit(-1);
	 }

	 new_times.actime=fs.st_atime;
	 new_times.modtime=fs.st_mtime;


	 if(utime(argv[2],&new_times)<0){
		 perror("utime");
		 exit(-1);
	 }
	 return 0;
	 
}

