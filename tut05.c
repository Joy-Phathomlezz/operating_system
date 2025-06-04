#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include <unistd.h>

int main(int argc , char* argv[]){
    int  fd[2] ; // file descriptor an key to perform op infile 
    if (pipe(fd) == -1){
        printf("error occured \n");
        return 1;
    }
    int id = fork();
    if(id == 0 ){
        //Inside child
        close(fd [0]) ;//close read end 
        printf("input : ");
        int x ;
        scanf("%d" , &x);
        printf("My Parent's ID : %d \n",getpid());
        write(fd[1] , &x ,sizeof(int));
        close(fd[1]);
    }else{
        //Parent process
        
        // close(fd[1]);
        int sample ;
        read(fd[0], &sample , sizeof(int));
        close(fd[0]);
        printf(" %d my boy send me LOVE %d\n" ,id,sample);
        
    }


    return 0 ;
}