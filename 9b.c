#include <stdio.h>
#include<stdlib.h>
#include <fcntl.h> 
#include <unistd.h> 

int main(int argc, char *argv[]) { 

	if (argc < 2) { 
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]); 
		return 1; 
	}
        int fd = open(argv[1],O_RDONLY);
	
	if(fd<0){
		perror("fd");
 		exit(EXIT_FAILURE);
	}
	char buf[21];
	if(read(fd,buf,20)<0){
	perror("read");
	 exit(EXIT_FAILURE);
        }
buf[20]='\0';
printf("First 20 Character:%s\n");
lseek(fd,10,SEEK_SET);
 if(read(fd,buf,20)<0){
        perror("read");
         exit(EXIT_FAILURE);
        }
buf[20]='\0';
printf("After 10 Character:%s\n");

lseek(fd, 10, SEEK_CUR); 
if (read(fd, buf, 20) != 20) { 
perror("read"); 
close(fd); 
return 1; 
} 
buf[20] = '\0'; 
printf("20 characters from current offset: %s\n", buf);
	
off_t file_size = lseek(fd, 0, SEEK_END);
if (file_size == -1) {
perror("lseek");
close(fd);
return 1;
}
printf("File size: %lld bytes\n", (long long) file_size);
close(fd);
return 0;
}
