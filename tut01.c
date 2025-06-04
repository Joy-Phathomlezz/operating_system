#include <stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
// // what is the difference between fork and getpid()
// void main () {
//     // // int id = fork();
//     // printf("hello world , %d \n" , (int)getpid());
//     // fork();
//     // printf("hello world , %d \n" , ;

//     printf("I am: %d\n", (int)getpid());

//     pid_t pid = fork();

//     printf("fork returned: %d\n", (int)pid);

//     if (pid < 0)
//     {
//         perror("fork failed");  
//     }

//     if (pid==0)
//     {
//         printf("I am the child with pid %d\n", (int)getpid());
//         // sleep(5);
//         // printf("Child exiting...\n");
//         // exit(0);
//     }

//     printf("I am the parent with pid %d, waiting for the child\n", (int)getpid());
//     // wait(NULL);
//     // printf("Parent ending. \n");

// }



int main() {
    pid_t pid = fork();  // Create a new process

    if (pid == 0) {
        // This block runs in the child process
        printf("Fork returned %d. This is the child process.\n", pid);
        printf("Child PID: %d, Parent PID: %d\n", getpid(), getppid());
    } else if (pid > 0) {
        wait(0);
        // This block runs in the parent process
        printf("Fork returned or Child PID : %d. This is the parent process.\n", pid);
        printf("Parent PID: %d\n", getpid());

    } else {
        // Fork failed
        printf("Fork failed!\n");
    }

    return 0;
}

