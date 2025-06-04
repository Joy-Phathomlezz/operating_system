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
            printf("I am immortal !!! %d\n",getpid());
            sleep(1);
        }
    }else{
        sleep(5);
        int i = kill(id , SIGKILL);
        wait(NULL);
        printf("Yam hai HUM : %d\n",getpid());
    }

    return 0;
}