//semaphore intro
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#define THREAD_NUM 6

sem_t semphore;

void *fn( void *arg){
    sem_wait(&semphore);
    usleep(500000);
    printf("Thread %d \n", *((int*)arg));
    free(arg);
    sem_post(&semphore);
}


int main () { 
    sem_init(&semphore , 0 ,2);
    pthread_t th[THREAD_NUM];
    for (int i = 0; i < THREAD_NUM; i++)
    {
        int *a = malloc(sizeof(int));
        *a = i;
        pthread_create(&th[i] , NULL , &fn , a);
    }
    
    for (int i = 0; i < THREAD_NUM; i++)
    {
        pthread_join(th[i] , NULL);
    }
    
    sem_destroy(&semphore);
    return 0;
}