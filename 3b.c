#include <stdio.h> 
#include <unistd.h> 
#include <fcntl.h> 
#include <dirent.h> 
#include <time.h> 
#include<sys/stat.h> 

int main (int argc,char* argv[]){
	struct dirent* dir;
	DIR * dp;

	int fd ;

	struct stat fs;
	 dp=opendir(argv[1]);

	 if(dp){
		 while(dir=readdir(dp)){
			 stat(dir->d_name,&fs);
			 printf("%ld %o %d %d %s %s \n",fs.st_ino,fs.st_mode,fs.st_uid,fs.st_gid,ctime(&fs.st_atime),dir->d_name);
		 }
	 }
	 return 0;
}
