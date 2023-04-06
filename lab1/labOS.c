#include <stdio.h>

// Define a struct to represent a process
typedef struct {
    int pid;      // Process ID
    int burst;    // Burst time (in CPU cycles)
} Process;

int main() {
    int n;  // Number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Initialize an array of processes
    Process processes[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the burst time of process %d: ", i+1);
        scanf("%d", &processes[i].burst);
        processes[i].pid = i+1;
    }

    // Calculate the average waiting time
    float avg_wait=0;
    float curr_wait=0;
    float curr_turnaround=0;
    float avg_turnaround=0;
    printf("\nProcess\tBurst\tWaiting\tTurnaround");
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            curr_wait = 0;
        } else {
            curr_wait += processes[i-1].burst;
        }
        curr_turnaround += processes[i].burst;
        avg_turnaround += curr_turnaround;
        avg_wait += curr_wait;
        printf("\n%d\t%d\t%.2f\t%.2f", processes[i].pid, processes[i].burst, curr_wait, curr_turnaround);
    }
    avg_wait /= n;
    avg_turnaround /= n;

    // Print the average waiting time
    printf("\nAverage waiting time: %.2f\n", avg_wait);
    printf("Average turnaround time: %.2f\n", avg_turnaround);

    return 0;
}
