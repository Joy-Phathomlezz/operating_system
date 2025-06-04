#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>
#include<sys/types.h>
#include<fcntl.h>

int main (int argc , char* argv[]){
    printf("creating \n");
    
    int create_status = mkfifo("named_pipe" , 0777);
    if (create_status == -1)
    {
        if (errno != EEXIST){
            perror("failed");
        }
    }
    printf("created \n");
    // this will stop as here only 1 end is working 
    int file_des = open("named_pipe",O_WRONLY);
    // cat the contents hten code will work
    printf("writing \n");
    // int file_des = open("named_pipe.txt",O_RDWR);
    int val = 100;
    int write_status = write(file_des, &val , sizeof(val));
    printf("written \n");
    if (write_status == -1)
    {
        perror("failed");
    }
    close(file_des);
    printf("closed \n");
    

return 0;
}