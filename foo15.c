#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *task(void *arg) {
    char *role = (char *)arg;

    if (role == "CTO") {  // CTO arrives late and leaves early
        usleep(1500000); // CTO arrives after 1.5 seconds
        printf("%s arrived late, quickly reviewing project roadmap.\n", role);
        usleep(500000);  // CTO finishes quickly
        printf("%s left early after reviewing.\n", role);
        pthread_exit(NULL);
    }

    printf("%s working on assigned tasks...\n", role);
    sleep(3); // Simulating normal work time

    printf("%s finished work.\n", role);
    return NULL;
}

int main() {
    pthread_t th[6];
    char *roles[6] = {"Frontend Engineer", "CTO", "Backend Engineer", "DevOps Engineer", "Database Specialist", "Security Analyst"};

    for (int i = 0; i < 6; i++)
        pthread_create(&th[i], NULL, task, roles[i]);

    for (int i = 0; i < 6; i++)
        pthread_join(th[i], NULL);

    printf("Tech Team all tasks completed.\n");
    return 0;
}
