// wait for process to finish print 1-10 
// 1-5 from child 
// 6-10 from parent 

#include<stdio.h>
#include<strings.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main (int argc , char* argv[] ){

    pid_t pid = fork(); 
    int n ;
    if( pid == 0 ){
        n=1;
        printf("child working : ");
        
    }else if (pid > 0)
    {
        wait(0);
        n = 6;
        printf(" parent working : \t");
    }
    
    int i ; 
    for (int i = n; i < n+5; i++)
    {
        printf("%d " , i);
        fflush(stdout);
    }

    if (pid != 0 ){
         //we cannot put this in parent block as then it would be executed at time 
        printf("\n");
    }

    printf(argc);
    return 0;
}