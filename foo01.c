// bash CLI: gcc -g -thread <file_name.c> -o <executable>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<sys/syscall.h>

void* thread_func(void* arg){
    printf("Thread ID (TID): %ld\n", syscall(SYS_gettid));
    printf("pthread_self: %lu\n", pthread_self());
    sleep(2);
    printf("|| processing\n");
    return NULL;
}
int main (int agc , char * agcv[]){
    pthread_t t1,t2 ;
    int id1 = pthread_create(&t1 , NULL , &thread_func , NULL);
    int id2 = pthread_create(&t2 , NULL , &thread_func , NULL);

    // printf("THread1 Id : %d\n" , gettid());
    // printf("THread1 Id : %d\n" , gettid());

    if (id1 && id2){    printf("threads are broken \n");}
     
    // waiting for threads to finish executing 
    pthread_join(t1 , NULL);
    pthread_join(t2 , NULL);

    printf("Main process PID : %d \n", getpid());
    return 0;
}