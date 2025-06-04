// returing from a worker thread with pthread_exit()

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *roll_dice(void *arg) {
    int *val = (int*)arg; // Copy argument
    int *result = malloc(sizeof(int)); // Allocate memory
    *result = (*val) * 2; // Store the computed value
    // return result;
    pthread_exit((void*)result);
}

int main() {
    // printf("helleo ");
    pthread_t th;
    int num = 5;
    void *ans; // Will store the return value

    pthread_create(&th, NULL, &roll_dice, &num);
    pthread_join(th, &ans);

    printf("%d\n", *(int*)ans); // Correctly prints 10
    free(ans); // Free allocated memory

    return 0;
}
