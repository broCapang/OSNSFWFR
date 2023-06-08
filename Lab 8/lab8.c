#include <stdio.h>

// Function to check whether a page exists in a frame or not
int find(int arr[], int n, int num) {
    for (int i = 0; i < n; i++)
        if (arr[i] == num)
            return 1;
    return 0;
}

// Function to print frames
void printFrames(int frames[], int capacity) {
    for (int i = 0; i < capacity; i++)
        if (frames[i] != -1)
            printf("%d ", frames[i]);
        else
            printf("-1 ");
}

void FIFO(int pages[], int n, int capacity) {
    int frame[capacity], fcount = 0;
    int miss = 0;

    // initialize frames
    for (int i = 0; i < capacity; i++)
        frame[i] = -1;

    printf("The starting frames are: ");
    printFrames(frame, capacity);
    printf("\n");
    printf("The page replacement process is:\n");

    // process each page
    for (int i = 0; i < n; i++) {
        if (find(frame, capacity, pages[i]) == 0) {
            miss++;
            frame[fcount % capacity] = pages[i];
            fcount++;
            printFrames(frame, capacity);
            printf(" PF Count %d\n", miss);
        } else {
            printFrames(frame, capacity);
            printf("\n");
        }
    }

    printf("The number of page faults is %d.\n", miss);
}

int main() {
    int n, capacity;

    printf("Enter the length of the reference string: ");
    scanf("%d", &n);
    int pages[n];
    
    printf("Enter the reference string: ");
    for(int i=0; i<n; i++)
        scanf("%d", &pages[i]);
    
    printf("Enter no. of frames: ");
    scanf("%d", &capacity);

    FIFO(pages, n, capacity);
    return 0;
}
