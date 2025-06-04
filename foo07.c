#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<pthread.h>

// infinite die parallel probability dice simulator 

void * dice (){
    int * face_Val = (int *)malloc(sizeof(int));
    *face_Val = 1+ (rand()%6);
    return face_Val;
}

int main(){
    int n = 100000;
    srand(time(NULL));

    pthread_t th[n];
    int *chances[n];
    int count[6] = {0};   // To store face occurrence count

    for (int i = 0; i < n; i++)
    {   
        int create_status = pthread_create(th+i, NULL, &dice, NULL);
        if (create_status != 0){return -1 ;}
    }
    
    for (int i = 0; i < n; i++)
    {
        pthread_join(th[i], (void**)&chances[i]);
        // printf("Dice %d rolled: %d\n", i+1, *chances[i]);

        // Increment the count for the face (1-6)
        count[(*chances[i]) - 1]++;
        free(chances[i]);
    }

    // Calculate percentage probability
    float prob[6];
    for (int i = 0; i < 6; i++) {
        prob[i] = (count[i] / (float)n) * 100;
    }

    // Display the probabilities
    printf("\nFace\tCount\tProbability\n");
    for (int i = 0; i < 6; i++) {
        printf("%d\t%d\t%.2f%%\n", i+1, count[i], prob[i]);
    }

    return 0;
}
