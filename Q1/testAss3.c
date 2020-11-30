#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
#define call 440

int main(int argc, char * argv){
	long pid;
	long tim;
	scanf("%ld", &pid);
	scanf("%ld", &tim);
	
	long ret = syscall(call,pid,tim);
	if(ret !=0) printf("works");
	else printf("doesnot work");
	return ret;
}
