//passing arguments to threads 

#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void *th_fun(void* arg){
    int tip = *(int*)arg;
    printf("Tip paid : $ %d\n",tip);
    free(arg);

}
int main(){ 

    int *tip = (int*)malloc(sizeof(int));
    *tip = 1000 ;
    pthread_t t;
    pthread_create(&t, NULL , &th_fun , tip);

    pthread_join(t , NULL);

    
    return 0 ;
}
