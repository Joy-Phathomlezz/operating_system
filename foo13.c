//gist of pthread_mutex_trylock

#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

// chefs are threads and stove is shared memory and fuel is mutex
pthread_mutex_t stoveMutex[3];
int stoveFuel[3] = {100,100,100};

void *fn (void * arg){

    for (int i = 0; i < 3; i++) {
        if (pthread_mutex_trylock(&stoveMutex[i]) == 0) {
            // Cooking
            int Fuelneed = rand() % 20;
            if (stoveFuel[i] - Fuelneed < 0) {
                printf("Fuel finished on stove %d\n", i + 1);
            } else {
                stoveFuel[i] -= Fuelneed;
                printf("Fuel left %d on stove %d\n", stoveFuel[i], i + 1);
            }
            usleep(500000); // Simulate cooking time
            pthread_mutex_unlock(&stoveMutex[i]);
            break;
        } else {
            if (i == 2) {  // Last stove is also locked
                printf("Waiting for a stove .......\n");
                usleep(300000);
                i = -1; // Reset loop index to retry
            }
        }
    } 
}

int main(int argc , char* arv[]){
    srand(time(NULL));
    int n = 10,s =3;
    pthread_t th[n];
    for (int i = 0; i < s; i++)
    {
        pthread_mutex_init(&stoveMutex[i],NULL);
        
    }
    

    for (int i = 0; i < n; i++)
    {
        pthread_create(&th[i],NULL,&fn,NULL);
        usleep(100000);
    }
    for (int i = 0; i < n; i++)
    {
       pthread_join(th[i],NULL);
    }
 
    for (int i = 0; i < s; i++)
    {
        pthread_mutex_destroy(&stoveMutex[i]);
    }
    
    return 0;
}