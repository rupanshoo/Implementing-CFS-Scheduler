/* Name: Rupanshoo Saxena
   Roll_Number: 2019096 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>

#define rtnice 440

int main(int argc, char* argv[]){
   long ppid;
   long sr_time;

   scanf("%ld",&sr_time);
   scanf("%ld",&ppid);

   long rt_Ret = syscall(rtnice,ppid,sr_time);
	if(rt_Ret !=0) printf("Works");
	else printf("Doesn't Work");
	return 0;
}