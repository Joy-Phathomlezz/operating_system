// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <sys/stat.h>
// #include <errno.h>
// #include<sys/types.h>
// #include<fcntl.h>
// #include<string.h>
// // make a fifo and send some data 

// int main(int argc , char* argv[]){
//     // to read and print the contents form the fifo
//     int store[5] = {0 , 0 ,0,0 ,0};
//     int fdesc = open("fIfO" , O_RDONLY);
//     if(fdesc == -1 ){return 1;}

//     for (int i = 0; i < 5; i++){
//         if (read(fdesc , &store[i] , sizeof(int)) == -1 ){
//             return 1;
//         }
//         printf("%d ",store[i]);
//     }
//     close(fdesc);
//     return 0 ;
// }
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int store[5] = {0};  // Array to store received data
    
    int fd = open("fIfO", O_RDONLY);
    if (fd == -1) {
        perror("open failed");
        return 1;
    }

    read(fd, store, sizeof(store));  // Read the full array in one go

    // Print the received array
    for (int i = 0; i < 5; i++) {
        printf("%d ", store[i]);
    }
    printf("\n");

    close(fd);
    return 0;
}
