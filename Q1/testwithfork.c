#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>

#define rtnice 440

int main(int argc, char* argv[]){
    long sr_time;
    scanf("%ld",sr_time);

    int forkID;
    forkID = fork();

    if(forkID==0){   //child process
        long rt_Ret = syscall(rtnice, getpid() ,sr_time);
        printf("\nI am the Child process\n");
    }

    else if(forkID>0){   //parent process
        printf("\nI am the parent process\n");
    }

    else{   //can't fork
        printf("Fork failed!!!");
    }

    return 0;
}