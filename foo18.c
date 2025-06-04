#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define THREAD_NUM 8 ;

//what each thread has rolled 
int diveValues[8] ;
int status[8] = {0};

void *rolldice(void* args){
    int index = * (int*)args;

}


int main(){

    return 0;
}