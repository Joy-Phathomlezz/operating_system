#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

typedef struct {
    int id;
    char *designation;
} Worker;

void *worker(void *arg) {
    Worker *w = (Worker *)arg;
    printf("[%s %d] Reporting for duty in the department.\n", w->designation, w->id);
    sleep(3);  // Simulating work
    printf("[%s %d] Completed tasks and leaving.\n", w->designation, w->id);
    return NULL;
}

int main() {
    int num_workers = 4;  // Number of workers
    pthread_t workers[num_workers];
    Worker w[num_workers];

    char *designations[] = {"Engineer", "Technician", "Supervisor", "Accountant"};

    for (int i = 0; i < num_workers; i++) {
        w[i].id = i + 1;
        w[i].designation = designations[i];  // Assign a role
        pthread_create(&workers[i], NULL, worker, &w[i]);
    }

    usleep(1500000);  // Manager stays for 1.5 seconds before leaving
    printf("[Manager] Manager is leaving the office. Workers continue their tasks.\n");
    
    pthread_exit(NULL);  // Manager (main thread) exits, but workers keep running
}
