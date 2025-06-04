#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<time.h>

void * rolldice (){
    int *val = (int *)malloc(sizeof(int));
    *val  = (rand()%6)+1;
    return (void*) val;
}


int main(){
    srand(time(NULL));
    pthread_t t1;
    int *res ;
    if(pthread_create(&t1 , NULL , &rolldice , NULL) != 0){return 1;};

    if(pthread_join(t1,(void**) &res) != 0){return 2;}
    printf("ans : %d ", *res);
    free(res);
    return 0;
}