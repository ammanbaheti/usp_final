#include<stdio.h>
#include<stdlib.h>
#include<setjmp.h>

static int global;
static jmp_buf buf;

void test(){
	int normal =10;
	register int r = 23;
	volatile int v = 43;
	global=34;

	int res = setjmp(buf);

	if(res==0){
		printf("Initial values:\n GLobal:%d Register:%d Volatile:%d Normal:%d\n",global,r,v,normal);
		r=78;
		v= 68;
		normal=11;
		global=23;
		 printf("Modified values:\n GLobal:%d Register:%d Volatile:%d Normal:%d\n",global,r,v,normal);
		 longjmp(buf,1);
	}
	else{
		printf("Longjmp Executed:\n");
		 printf("Restored Values :\n GLobal:%d Register:%d Volatile:%d Normal:%d\n",global,r,v,normal);
	}
}

int main(){
	test();
	return 0;
}
