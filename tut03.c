#include<string.h>
#include<stdlib.h>
#include <stdio.h>
#include<unistd.h>
#include<sys/wait.h>


int main(int argc , char* argv[]){
    int id = fork();
    if (id  == 0 )
    {
        sleep(2);
    }
    
    printf("curr id : %d \t parent id : %d \t fork id : %d \n" , getpid(), getppid(), id);
    // printf("curr id : %d \t parent id : %d " , getpid(), id);
    int res  = wait(NULL);
    if (res  == -1 )
    {
        printf("no children to wait for \n");
    }else{
        printf("%d finished execution \n " ,  res);
    }
    
    return 0;
}