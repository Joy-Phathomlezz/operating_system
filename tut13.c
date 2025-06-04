#include<stdio.h> 
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<errno.h>
#include<unistd.h>
#include<fcntl.h>
int main(int argc , char * argv[]){
    int id = fork();
    if (id == -1)
    {
        printf("fork failed\n");
    }else if(id == 0){
        int fd = open("pingResults.txt", O_WRONLY | O_CREAT,0777);
        printf("previous fd : %d ",fd);
        int fd2 = dup2(fd , STDOUT_FILENO);
        close(fd);
        printf("output in file");
        printf("previous fd : %d \n",fd2);
        execlp("ping","ping","-c" , "1" , "google.com" , NULL);
    }else{
        int wst;
        wait(&wst);
        
    
        
                    if (WIFEXITED(wst) && WEXITSTATUS(wst) == 0)
            {
                printf("process is done\n");
            }      
        
        
    }
    
    return 0;
}