#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
// execute ping -c 3 google.com | grep rtt
int main(){
    int fd[2];
    // pipe for fd creation
    if(pipe(fd) == -1 ){return -1;}
    // for child 1 fork 
    int pid1= fork();
    if(pid1 == 0){
        // lets redirect the output 
        dup2(fd[1],STDOUT_FILENO);
        //closing the unused ends 
        close(fd[0]);
        close(fd[1]);   
        execlp("ping","ping","-c","3","google.com",NULL);
    }
    // for child2 fork
    int pid2 = fork();
    if (pid2==0)
    {
         // lets redirect the output 
         dup2(fd[0],STDIN_FILENO);
         //closing the unused ends 
         close(fd[0]);
         close(fd[1]);   
        execlp("grep" , "grep" , "rtt" ,NULL);
    }
    //closing the pipe of parent otherwise grep will not stop
    close(fd[0]);
    close(fd[1]);

    //waiting for the child1 to get killed
    waitpid(pid1,NULL,0);
    waitpid(pid2,NULL,0);
    return 0;
}


//reference 
/*

int fd[2];
pipe(fd);
int pid = fork();

if(pid == 0) {
    // Redirect stdout (1) to pipe's write end
    dup2(fd[1], STDOUT_FILENO);
    close(fd[0]); // Close read end
    close(fd[1]); // Close write end (dup2 took over)
    
    execlp("ls", "ls", NULL); // Output goes to pipe
} else {
    close(fd[1]); // Close write end
    char buffer[100];
    read(fd[0], buffer, sizeof(buffer));
    printf("Received: %s", buffer);

}*/
