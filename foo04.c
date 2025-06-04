#include<stdlib.h>
#include<pthread.h>
#include<stdio.h>
int mails = 1;
//define mutex
pthread_mutex_t mutex ;

void * credit(){
    for (int i = 0; i < 100000; i++)
    {
        //lock the mutex
        pthread_mutex_lock(&mutex);
        mails++;
        pthread_mutex_unlock(&mutex);
    }                   
}
int main(){

    pthread_t t1,t2,t3,t4,t5;

    //init the mutex
    pthread_mutex_init(&mutex , NULL);
    
    pthread_create(&t2,NULL , &credit , NULL);
    pthread_create(&t1,NULL , &credit, NULL);
    pthread_create(&t3,NULL , &credit, NULL);
    pthread_create(&t4,NULL , &credit, NULL);
    pthread_create(&t5,NULL , &credit, NULL);

    pthread_join(t1 , NULL);
    pthread_join(t2 , NULL);
    pthread_join(t3 , NULL);
    pthread_join(t4 , NULL);
    pthread_join(t5 , NULL);

    //frees the mutex 
    pthread_mutex_destroy(&mutex);

    printf("%d\n",mails);
    return 0;
}