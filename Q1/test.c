/*
Name: Rupanshoo Saxena
Roll no.- 2019096 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>   //for fork
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/time.h>

#define rtnice 440      //ID of the rtnice syscall
#define checkVal 1000000000     

int main(int argc, char* argv[]){
    //user input to get soft real time
    long sr_time;
    scanf("%ld",&sr_time);

    struct timeval start_time_child, end_time_child, start_time_parent, end_time_parent;

    int forkID;
    forkID = fork();

    if(forkID==0){   //child process
        printf("Child process - %d\n",getpid());

        gettimeofday(&start_time_child,NULL);  //to record start time of task
        for(int i=0;i<checkVal;i++);           //task to be performed
        gettimeofday(&end_time_child,NULL);    //to record end time of task

        //tv.sec -> in seconds, tv.usec->in microseconds(10^-6)
        printf("time with vruntime = %lf\n",(double)(end_time_child.tv_usec - start_time_child.tv_usec)/1000 + (double)(end_time_child.tv_sec - start_time_child.tv_sec)*1000);
    }


    else if(forkID>0){   //parent process
        printf("Parent process - %d\n",getpid());

        long rt_Ret = syscall(rtnice, (long)getpid() ,sr_time);   //giving priority to parent process to finish faster

        gettimeofday(&start_time_parent,NULL);
        for(int i=0;i<checkVal;i++);
        gettimeofday(&end_time_parent,NULL);

        printf("time with soft-realtime = %lf\n",(double)(end_time_parent.tv_usec - start_time_parent.tv_usec)/1000 + (double)(end_time_parent.tv_sec - start_time_parent.tv_sec)*1000);

    }


    else{   //can't fork
        printf("Fork failed!!!");
    }

    return 0;
}
