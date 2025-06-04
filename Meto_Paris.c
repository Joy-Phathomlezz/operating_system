#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <string.h>

#define METRO_COUNT 15
#define PLATFORM_COUNT 4

sem_t platform; // Semaphore for platform availability

typedef struct {
    int id;
    char *from;
    char *to;
} MetroInfo;

// List of stations (variable-length names)
char *stations[] = {
    "Gare du Nord", "Chatelet-Les Halles", "Saint-Michel Notre Dame","Montparnasse", "Gare de Lyon", "La Defense","Nation", "Bercy", "Invalides","Austerlitz", "Concorde", "Opera","Bastille", "Porte Maillot", "Denfert-Rochereau"
};

// Function to format station names for uniform output (25-character width)
void format_station(char *formatted, const char *original) {
    snprintf(formatted, 26, "%-25s", original); // Left-align and pad with spaces
}

// Function to print the table header
void print_table_header() {
    printf("\n%-12s | %-8s | %-25s | %-25s | %-6s | %-9s\n", 
           "SIGNAL", "METRO", "COMING FROM", "GOING TO", "TIME", "PLATFORM");
    printf("----------------------------------------------------------------------------------------------------\n");
}

// Metro thread function
void *metro(void *arg) {
    MetroInfo *info = (MetroInfo *)arg;

    char from_formatted[26], to_formatted[26];
    format_station(from_formatted, info->from);
    format_station(to_formatted, info->to);

    printf("🟡 WAITING   | %-8d | %-25s | %-25s | %-6s | %-9s\n", 
           info->id, from_formatted, to_formatted, "--", "--");

    sem_wait(&platform); // Wait for an available platform

    int remaining_platforms;
    sem_getvalue(&platform, &remaining_platforms); // Get available platforms
    int platform_id = PLATFORM_COUNT - remaining_platforms; // Assign platform ID

    printf("🟢 ARRIVING  | %-8d | %-25s | %-25s | %-6d | %-9d\n", 
           info->id, from_formatted, to_formatted, 3, platform_id);

    sleep(3); // Simulate time at the station

    printf("🔴 LEAVING   | %-8d | %-25s | %-25s | %-6s | %-9d\n", 
           info->id, from_formatted, to_formatted, "--", platform_id);

    sem_post(&platform); // Release the platform
    free(info); // Free allocated memory
    return NULL;
}

int main() {
    pthread_t metros[METRO_COUNT];
    sem_init(&platform, 0, PLATFORM_COUNT); // Initialize semaphore with available platforms

    print_table_header();

    for (int i = 0; i < METRO_COUNT; i++) {
        MetroInfo *info = malloc(sizeof(MetroInfo)); // Allocate memory for metro info
        if (!info) {
            perror("Failed to allocate memory");
            exit(1);
        }

        info->id = i + 1;
        info->from = stations[i % 15]; 
        info->to = stations[(i + 5) % 15];

        if (pthread_create(&metros[i], NULL, metro, info) != 0) {
            perror("Failed to create thread");
            free(info);
        }

        sleep(1); // Stagger metro arrivals slightly
    }

    for (int i = 0; i < METRO_COUNT; i++) {
        pthread_join(metros[i], NULL);
    }

    sem_destroy(&platform); // Destroy the semaphore
    printf("\n🚉 All metros have completed their journey.\n");
    return 0;
}


//patform 4 is not used make the code do that 