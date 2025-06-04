

//passing arguments to threads 

#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

int prime[] = {2,3,5,7,11,13,17,19,23,27,29};

void *th_fun(void* arg){
    int tip = *(int*)arg;
    printf("Element %d\n",prime[tip]);
    free(arg);

}
int main(){ 

    pthread_t th[10] ;
    int i ;
    for ( i = 0; i < 10; i++)
    {
        int *tip = (int*)malloc(sizeof(int));
        *tip =  i;
        if (pthread_create(&th[i],NULL,&th_fun,tip) != 0){
            return -1;
        }
        printf("thread %d is started \n",i); 
    }
    
    for (i = 0; i < 10; i++)
    {
        if (pthread_join(th[i],NULL)!= 0){
            return -1;
        }       
        // printf("thread %d has finished \n",i);  
    }
    return 0 ;
}
