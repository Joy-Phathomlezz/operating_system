#include <stdio.h>
#include <stdlib.h>

void* name() {
    int *p = (int*)malloc(sizeof(int));
    *p = 10;
    void **q = (void**)&p;   // Create void** to store int* address
    return (void*)q;        // Return void* (but actually void**)
}

int main() {
    void *ptr = name();       // Receive void* from function

    void **q = (void**)ptr;   // Convert void* to void**
    int *p = *(int**)q;       // Convert void* to int* and dereference once

    printf("%d\n", *p);       // Access the value
    free(p);                  // Free allocated memory
    return 0;
}
