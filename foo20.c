//detaching threads from main 
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <stdio.h>

void* work(){
    printf("Detached thread is running...\n");
    sleep(2);
    printf("Detached thread finished.\n");
}

int main(int argc , char* argv[]){ 
    pthread_t th[3];
    pthread_attr_t detachedthread;

    pthread_attr_init(&detachedthread);

    pthread_attr_setdetachstate(&detachedthread,PTHREAD_CREATE_DETACHED);

    for (int i = 0; i < 3; i++)
    {
        pthread_create(&th[i],&detachedthread, &work , NULL);
    }
    
    pthread_attr_destroy(&detachedthread);

    //All threads are terminated , status returned to OS
    //return 0 

    pthread_exit(0);
}