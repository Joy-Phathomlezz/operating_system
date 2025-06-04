//detaching threads from main 
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <stdio.h>

void* work(){
    printf("Work is DONE\n");
}

int main(int argc , char* argv[]){ 
    pthread_t th[3];

    for (int i = 0; i < 3; i++)
    {
        pthread_create(&th[i],NULL , &work , NULL);
        pthread_detach(th[i]);
    }
    

    //All threads are terminated , status returned to OS
    //return 0 

    pthread_exit(0);
}