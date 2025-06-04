#include<stdlib.h>
#include<pthread.h>
#include<stdio.h>
int mails = 10;

void * credit(){
    // int tmp = bal;
    for (int i = 0; i < 100000; i++)
    {
        mails++;
    }
    // reads mails 
    // increment in register 
    // writes mails

    // movl	mails(%rip), %eax
	// addl	$1, %eax
	// movl	%eax, mails(%rip)
}
int main(){

    pthread_t t1,t2;
    
    pthread_create(&t2,NULL , &credit , NULL);
    pthread_create(&t1,NULL , &credit, NULL);

    pthread_join(t1 , NULL);
    pthread_join(t2 , NULL);

    printf("%d\n",mails);
    return 0;
}