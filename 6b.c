#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc,char* argv[]){
  if(argc!=2){
                printf("Source <filename>\n");
                exit(-1);
        }	
	int fd =  open(argv[1],O_RDWR);

	struct flock fvar;

	fvar.l_type=F_WRLCK;
	fvar.l_whence=SEEK_END;
	fvar.l_start=-100;
	fvar.l_len=100;

	printf("Press Enter to get lock\n");
	getchar();
	printf("Trying to get the lock...\n");
	
	if(fcntl(fd,F_SETLK,&fvar)<0){
		fcntl(fd,F_GETLK,&fvar);
		printf("Lock Occupied by the process with pid : %d\n",fvar.l_pid);
		 close(fd);
                return -1;
	}
	printf("LOCKED\n");
	lseek(fd,-50,SEEK_END);
	char buf[100]={0};

	read(fd,buf,50);
	puts(buf);
	printf("Press Enter to unlock\n");
        getchar();
	fvar.l_type=F_UNLCK;
	fcntl(fd,F_SETLK,&fvar);
	printf("Unlocked\n");
	close(fd);
	return 0;
}


