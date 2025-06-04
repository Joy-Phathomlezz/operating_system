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
        execlp("ping","ping","-c" ,"1","google.com", NULL);
        printf("soory \n");
    }else{
        int wait_status ;
        
        wait(&wait_status);
        if (WIFEXITED(wait_status))
        {
            int statusCode = WEXITSTATUS(wait_status);
            if (statusCode == 0 )
            {
                printf("success \n");
            }else{
                printf("%d failed \n" , statusCode);
            }
            
        }
        
        printf("parent creates a exec call\n");
    }
    
    return 0;
}