#include <stdio.h>
#include<stdlib.h>
#include<errno.h>
#include <fcntl.h>
#include<unistd.h>

int main(int argc ,char* argv[]){
    int fd;

    // using the flock stuct for write lock
    struct flock fl = {
        .l_type = F_WRLCK,
        .l_whence = SEEK_SET,
        .l_start = 0,
        .l_len = 0,
        .l_pid = 0
    };

    //assing the pid value to the struct pid
    fl.l_pid = getpid();

    fd = open("locker.txt",O_RDWR);

    fcntl(fd,F_SETLKW,&fl);
    printf("Simulating work\n");

    printf("unlocking \n");
    fl.l_type = F_UNLCK;

    fcntl(fd,F_SETLK,&fl);
    close(fd);
    return 0;
}