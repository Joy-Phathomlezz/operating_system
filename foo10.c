// passing and returning from threads

//passing arguments to threads 

#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

int arr[] = {1,2,3,4,5,6,7,8,9,10};

void *th_fun(void* arg){
    int i = *(int*)arg;
    int sum = 0;
    for (int j = 0; j < 5; j++){
        sum+=arr[i+j];
    }
    
    printf("Sum : %d\n",sum);
    //integer pointer dereferenced value is returned
    *(int*)arg = sum;
    return arg;
}
int main(){ 

    pthread_t th[2] ;
    int i ;
    for ( i = 0; i < 2; i++)
    {
        int* a = (int* )malloc(sizeof(int));
        *a = i*5;
        if (pthread_create(&th[i],NULL,&th_fun,a) != 0){
            return -1;
        }
        // printf("thread %d is started \n",i); 
    }
    
    int globalSum = 0 ;
    for (i = 0; i < 2; i++)
    {   
        int *ans; // an int type pointer
        // addres(&) of pointer = ** ptr
        if (pthread_join(th[i], (void**)&ans)!= 0)
        { 
            return -1;
        }  
        
        globalSum += *(ans);
        free(ans);
    }
    
    printf("%d \n",globalSum);  
    
    return 0 ;
}
