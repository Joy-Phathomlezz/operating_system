// To execute another program throuch c code
// exec family of functions 

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>

int main(int argc , char * argv[] , char* envp[]){
    // printf("hello");
    // char *args[] = {"pwd",NULL};
    // execvp(args[0],args);
    
    // execlp("pwd" , "pwd" , NULL);
    // execlp("ping" , "ping" ,"google.com", NULL);
    char* arr[] = {
        "ping",
        "google.com",
        NULL
    };
    char* env[] = {
        "TEST = env ",
        NULL
    };
    // execvp("ping",arr );
    execvpe("ping",arr,env );
    perror("failed");
    return 0;
}