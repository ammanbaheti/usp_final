/*#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>

int main(int argc,char* argv[]){
	struct stat fs;

	if(stat(argv[1],&fs)<0){
		printf("Error  while accessing the fs struct\n");
		exit(-1);
	}
	printf("File Size: %ld\n No of Links: %ld\n No of Inodes: %ld\n Mode: %o\n Last Modification Time: %d\n",fs.st_size,fs.st_nlink,fs.st_ino,fs.st_mode,ctime(&fs.st_mtime));
	return 0;
}*/
#include <stdio.h>
#include <sys/stat.h>
int main(int argc, char *argv[]) {
if (argc < 2) {
fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
return 1;
}
struct stat file_stat;
if (stat(argv[1], &file_stat) == -1) {
perror("stat");
return 1;
}
printf("File: %s\n", argv[1]);
printf("Size: %lld bytes\n", (long long) file_stat.st_size);
printf("Permissions: %o\n", file_stat.st_mode & 0777);
printf("Number of Links: %ld\n", (long) file_stat.st_nlink);
printf("Owner: UID=%ld, GID=%ld\n", (long) file_stat.st_uid, (long) file_stat.st_gid);
printf("Last Access Time: %ld\n", (long) file_stat.st_atime);
return 0;
}
