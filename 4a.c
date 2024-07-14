#include<stdio.h> 
#include<stdlib.h> 
#include<fcntl.h> 
#include<unistd.h> 
#include<sys/stat.h> 
#include<sys/types.h>

int main(int argc,char* argv[]){
	if(argc==3){
		if(link(argv[1],argv[2])==0){
			printf("Hard Link Created between %s and %s \n",argv[1],argv[2]);
			return 0;
		}
	}
	if(argc==4){
		if(symlink(argv[1],argv[3])==0){
			  printf("Soft Link Created between %s and %s \n",argv[1],argv[3]);
                        return 0;
                }
        }
}
