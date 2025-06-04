// potential deadlocks 
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <stdio.h>
#include <stdbool.h>
#define _GNU_SOURCE 
#define THREAD_NUM  5

pthread_mutex_t mutex;


void* routine(){
   pthread_mutex_lock(&mutex); 
   pthread_mutex_lock(&mutex); 

    printf("Recursive mutexes \n");

   pthread_mutex_unlock(&mutex); 
   pthread_mutex_unlock(&mutex); 
   
}

int main(int argc , char* argv[]){ 
    pthread_t th[THREAD_NUM];
    pthread_mutexattr_t recAtt;

    pthread_mutexattr_init(&recAtt);
    pthread_mutexattr_settype(&recAtt,PTHREAD_MUTEX_RECURSIVE_NP);
    pthread_mutex_init(&mutex , &recAtt);

    for (int i = 0; i < THREAD_NUM ; i++)
    {
        pthread_create(&th[i],NULL , &routine , NULL);
    }
    
    for (size_t i = 0; i < THREAD_NUM; i++)
    {
        pthread_join(th[i],NULL);
    }

    pthread_attr_destroy(&recAtt);
    pthread_mutex_destroy(&mutex);
    
    return 0;
}