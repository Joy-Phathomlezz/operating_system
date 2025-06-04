// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <sys/stat.h>
// #include <errno.h>
// #include<sys/types.h>
// #include<fcntl.h>

// // make a fifo and send some data 

// int main(int argc , char* argv[]){
//     // fifo created alread thru terminal named "fIfO"
//     int fdesc = open("fIfO" , O_WRONLY); 
//     if( fdesc == -1 ){ return 1;}
//     printf("fifo opened \n");

//     int arr [] ={10,13,15,12};
//     for (int i = 0; i < 5; i++)
//     {
//         if (write(fdesc , &arr[i] , sizeof(int)) ==  -1 ){return 1 ;}
//     } 
//     printf("Array written \n");
//     close(fdesc); 
//     return 0 ;
// }

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    int arr[5] = {1, 2, 3, 4, 5,7,8,9,10};
    
    int fd = open("fIfO", O_WRONLY);
    if (fd == -1) {
        perror("open failed");
        return 1;
    }

    write(fd, arr, sizeof(arr));  // Write the full array at once
    close(fd);
    return 0;
}
