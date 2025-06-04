#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

pthread_mutex_t mutex;
pthread_cond_t light;

int is_green = 0;
int cars_waiting = 0;

void* traffic_light(void *arg){
    while (1)
    {
        sleep(3);

        pthread_mutex_lock(&mutex);
        is_green = 1;
        printf("[SIGNAL] Green Light! Cars can pass now.\n");

        // Allow all cars to pass
        pthread_cond_broadcast(&light);

        sleep(2);
        is_green = 0;
        printf("[SIGNAL] Red Light! Cars must stop.\n");

        pthread_mutex_unlock(&mutex);
    }
}

void* car(void *arg){
    int id = *((int*)arg);

    pthread_mutex_lock(&mutex);
    printf("[CAR %d] Arrived at signal.\n", id);

    while (is_green == 0)
    {
        cars_waiting++;
        printf("[CAR %d] Waiting for green signal...\n", id);
        pthread_cond_wait(&light, &mutex);
        cars_waiting--;
    }

    printf("[CAR %d] Crossing the road now.\n", id);
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main(){
    pthread_t light_thread;
    pthread_t th[5];

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&light, NULL);

    pthread_create(&light_thread, NULL, &traffic_light, NULL);

    for (int i = 0; i < 5; i++){
        int *id = malloc(sizeof(int));
        *id = i+1;
        pthread_create(&th[i], NULL, &car, id);
        sleep(rand()%3 + 1); // Cars arrive randomly
    }

    for (int i = 0; i < 5; i++){
        pthread_join(th[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&light);

    return 0;
}
