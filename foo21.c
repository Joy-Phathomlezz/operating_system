// potential deadlocks 
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <stdio.h>
#include <stdbool.h>

pthread_mutex_t mutexGenrator;
pthread_mutex_t mutexBattery;

bool generator = false;
bool battery = false;

void* PowerBackUp(){
    
    if (rand() % 2 == 0 )
    {
        pthread_mutex_lock(&mutexBattery);
        printf("need Generator!\n");
        pthread_mutex_lock(&mutexGenrator);
    }else{
        pthread_mutex_lock(&mutexGenrator);
        printf("need Battery!\n");
        pthread_mutex_lock(&mutexBattery);
    }

    battery = true;
    generator = true;

    printf("both available... \n");
    pthread_mutex_unlock(&mutexBattery);
    pthread_mutex_unlock(&mutexGenrator);
}

int main(int argc , char* argv[]){ 
    pthread_t th[3];

    for (int i = 0; i < 3; i++)
    {
        pthread_create(&th[i],NULL , &PowerBackUp , NULL);
    }
    
    for (size_t i = 0; i < 3; i++)
    {
        pthread_join(th[i],NULL);
    }
    
    printf("Backup complete");
    return 0;
}