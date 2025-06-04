// executing ls -l from this process ;
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include <errno.h>

int main (int argc , char * argv[]){

    // execute without the full path 
    // execlp("ls","ls","-l","-h","-a" , NULL);
    execlp("man","man","ls" , NULL);
    return 0 ;
}
