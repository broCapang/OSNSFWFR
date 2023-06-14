#include <stdio.h>

#define MAX_PHILOSOPHERS 10

int philosophers[MAX_PHILOSOPHERS] = {0};  // Status of philosophers: 0 - thinking, 1 - hungry, 2 - eating
int numHungry = 0;  // Number of hungry philosophers
int hungryPositions[MAX_PHILOSOPHERS] = {0};  // Positions of hungry philosophers

void promptUser() {
    printf("Choose one of the following:\n");
    printf("1. One can eat at a time.\n");
    printf("2. Two can eat at a time.\n");
    printf("3. Exit.\n");
}

void printStatus() {
    for (int i = 0; i < numHungry; i++) {
        int philosopher = hungryPositions[i];
        switch (philosophers[philosopher]) {
            case 0:
                printf("P%d is thinking\n", philosopher);
                break;
            case 2:
                printf("P%d is eating\n", philosopher);
                break;
            default:
                printf("P%d is waiting\n", philosopher);
                break;
        }
    }
}

void allowEating(int p1, int p2) {
    for (int i = 0; i < numHungry; i++) {
        int philosopher = hungryPositions[i];
        if (philosopher != p1 && philosopher != p2) {
            philosophers[philosopher] = 0;  // Set non-eating philosophers to thinking
        }
    }
}

void handleOneAtATime() {
    printf("One can eat at a time.\n");
    for (int i = 0; i < numHungry; i++) {
        int philosopher = hungryPositions[i];
        philosophers[philosopher] = 2;  // Set the philosopher to eating
        printStatus();
        philosophers[philosopher] = 0;  // Set the philosopher to thinking after eating
        printStatus();
    }
}

void handleTwoAtATime() {
    printf("Two can eat at a time.\n");
    int combinations = 0;
    for (int i = 0; i < numHungry - 1; i++) {
        for (int j = i + 1; j < numHungry; j++) {
            int p1 = hungryPositions[i];
            int p2 = hungryPositions[j];
            combinations++;
            printf("Combination %d: P%d and P%d are eating. ", combinations, p1, p2);
            allowEating(p1, p2);
            printStatus();
            allowEating(-1, -1);  // Reset the philosophers to thinking
        }
    }
    printf("\n");
}

int main() {
    int numPhilosophers;
    printf("Enter the number of philosophers: ");
    scanf("%d", &numPhilosophers);

    printf("How many are hungry: ");
    scanf("%d", &numHungry);

    if (numHungry == numPhilosophers) {
        printf("Error: All philosophers are hungry. Deadlock situation!\n");
        return 0;
    }

    for (int i = 0; i < numHungry; i++) {
        printf("Enter philosopher %d's position: ", i + 1);
        scanf("%d", &hungryPositions[i]);
        philosophers[hungryPositions[i]] = 1;  // Set hungry philosophers' status to 1
    }

    while (1) {
        promptUser();

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                handleOneAtATime();
                break;
            case 2:
                handleTwoAtATime();
                break;
            case 3:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }

    return 0;
}
