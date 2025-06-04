#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/wait.h>
#include<unistd.h>
int main( int argc , char * argv[]){

    int pid  = fork();
    if (pid == -1)
    {
        return -1;
    }
    
    if(pid == 0  )
    {
        // execlp("ls","ls","-a" , NULL);
        execlp("ping","ping","-c" ,"3","google.com", NULL);
    }else{
        wait(NULL);
        printf("parent creates a exec call");
    }
    
    return 0;
}