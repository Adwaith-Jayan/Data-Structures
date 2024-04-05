#include <stdio.h>

#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

int available[MAX_RESOURCES];
int maximum[MAX_PROCESSES][MAX_RESOURCES];
int allocation[MAX_PROCESSES][MAX_RESOURCES];
int need[MAX_PROCESSES][MAX_RESOURCES];
int finish[MAX_PROCESSES];

int num_processes, num_resources;

int is_safe() {
    int work[MAX_RESOURCES];
    int i, j, k, safe_sequence[MAX_PROCESSES];
    int num_completed = 0;

    // Initialize work as available
    for (i = 0; i < num_resources; ++i)
        work[i] = available[i];

    while (num_completed < num_processes) {
        int found = 0;
        for (i = 0; i < num_processes; ++i) {
            if (!finish[i]) {
                int can_allocate = 1;
                for (j = 0; j < num_resources; ++j) {
                    if (need[i][j] > work[j]) {
                        can_allocate = 0;
                        break;
                    }
                }
                if (can_allocate) {
                    // Allocate resources to process i
                    for (j = 0; j < num_resources; ++j)
                        work[j] += allocation[i][j];
                    finish[i] = 1;
                    safe_sequence[num_completed++] = i;
                    found = 1;
                }
            }
        }
        if (!found) {
            printf("System is in unsafe state!\n");
            return 0;
        }
    }

    printf("Safe Sequence: ");
    for (i = 0; i < num_processes - 1; ++i)
        printf("P%d -> ", safe_sequence[i]);
    printf("P%d\n", safe_sequence[num_processes - 1]);

    return 1;
}

int main() {
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    printf("Enter the number of resources: ");
    scanf("%d", &num_resources);

    printf("Enter the available resources: ");
    for (int i = 0; i < num_resources; ++i)
        scanf("%d", &available[i]);

    printf("Enter the maximum resources required by each process: \n");
    for (int i = 0; i < num_processes; ++i)
        for (int j = 0; j < num_resources; ++j)
            scanf("%d", &maximum[i][j]);

    printf("Enter the allocated resources for each process: \n");
    for (int i = 0; i < num_processes; ++i)
        for (int j = 0; j < num_resources; ++j) {
            scanf("%d", &allocation[i][j]);
            need[i][j] = maximum[i][j] - allocation[i][j];
        }

    // Initialize finish array
    for (int i = 0; i < num_processes; ++i)
        finish[i] = 0;

    if (is_safe())
        printf("System is in safe state.\n");
    else
        printf("System is in unsafe state.\n");

    return 0;
}