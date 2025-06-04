#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc  , char* argv[]){
    int id1 = fork();
    int id2 = fork();

    if (id1 == 0 ){
        if(id2 == 0 ){
            printf("I am process M %d %d \n" , getpid(),getppid());
        }else{
            printf("I am process Y %d %d\n" , getpid(),getppid());
        }
    }
    else{
        if (id2 == 0 ){
            printf("I am process Z %d %d\n" , getpid(),getppid());
        }else{
            printf("I am process X %d %d\n" , getpid(),getppid());
        }
    }
    return 0;
}