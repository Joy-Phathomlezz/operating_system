#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include <syscall.h>
#include<math.h>

int val = 100;
// memory is shared so val cannot be changed
void* Double(){
    val=val*2;
    sleep(2);
    printf("%d " , val);
    printf("I %ld owe this \n",syscall(SYS_gettid));
    return NULL;
}   
void* Half(){
    val=val/2;
    sleep(2);
    printf("%d " , val);
    printf("I %ld owe this \n",syscall(SYS_gettid));
    return NULL;
}
int main(){
    pthread_t t1,t2;
    
    pthread_create(&t2,NULL , &Double , NULL);
    pthread_create(&t1,NULL , &Half , NULL);

    pthread_join(t1 , NULL);
    pthread_join(t2 , NULL);
    return 0;
}