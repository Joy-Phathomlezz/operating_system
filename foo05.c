#include<stdlib.h>
#include<pthread.h>
#include<stdio.h>
// multiple threads without mutex using for loop
//concurrent execution
void * fun(){
    printf(" | ");   
}

int main(){

    pthread_t th[5] ;
    int i ;
    for ( i = 0; i < 5; i++)
    {

        if (pthread_create(th+i,NULL,&fun,NULL) != 0){
            return -1;
        }
        printf("thread %d is started \n",i);  
    }
    
    for (i = 0; i < 5; i++)
    {
        if (pthread_join(th[i],NULL)!= 0){
            return -1;
        }       
        printf("thread %d has finished \n",i);  
    }
    printf("threads done \n");
    return 0;
}