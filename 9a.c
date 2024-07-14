#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){

	mode_t new_mask=0022;
	mode_t old_mask=umask(new_mask);

	printf("Old Mask: %03o  New Mask = %03o \n",old_mask,new_mask);
	 mode_t mode = 0644;

	 int fd = open("9atest.txt",O_CREAT|O_WRONLY,0777);
	 if (fd == -1) {
		perror("open");
		return 1;
	}		
	
	close(fd);
	if (chmod("9atest.txt", mode) == -1) {
	perror("chmod");
	return 1;
	}
	printf("Changed permissions of 9atest.txt to %03o\n", mode);
	return 0;
}
