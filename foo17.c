#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>


pthread_barrier_t barrier;

void *routine (void* args){
    printf("waiting at the barrier\n");
    pthread_barrier_wait(&barrier);
    printf("passed barrier\n");
}

int main(){
    int n  = 10 ;
    pthread_t th[n];
    pthread_barrier_init(&barrier ,NULL,5);
    for (int i = 0; i < n; i++)
    {
        pthread_create(&th[i],NULL,&routine , NULL);
    }
    
    for (int i = 0; i < n; i++)
    {
        pthread_join(th[i],NULL);
    }
    pthread_barrier_destroy(&barrier);
    
}