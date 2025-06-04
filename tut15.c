#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<signal.h>
// singnals - stop an infinte loop 
int main(int argc , char* argv[]){
    int id = fork();
    if(id  == 0 ){
        while (1)
        {
            printf("executing \n");
            sleep(1);
        }
    }else{//the child block will execute after this as 
        // the parent executes before the child even runs
        printf("SIGSTOP signal \n");
        kill(id , SIGSTOP);
        printf("chid stopeed \n");

        int t ;
        do {
            printf("Time of execution : ");
            scanf("%d",&t);
            if(t>0){
                kill(id , SIGCONT);
                printf("chid Resumed \n");
                sleep(t);
                kill(id , SIGSTOP);
            }
        }while(t>0);        
        printf("chid termination success \n");
        kill(id , SIGKILL);
        //to free resources 
        wait(NULL);
    }
    return 0;
}