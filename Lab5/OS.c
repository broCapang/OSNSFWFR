#include <stdio.h>

void firstFitAllocation() {
    int numBlocks, numProcesses;
    printf("Enter the number of blocks: ");
    scanf("%d", &numBlocks);
    printf("Enter the number of processes: ");
    scanf("%d", &numProcesses);

    int blockSizes[numBlocks], blockAllocated[numBlocks], blockMemory[numBlocks];
    int processSizes[numProcesses], processAllocated[numProcesses];

    printf("\nEnter the size of the blocks:\n");
    for (int i = 0; i < numBlocks; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &blockSizes[i]);
        blockAllocated[i] = 0; // Set block as unallocated
        blockMemory[i] = blockSizes[i]; // Initialize available memory of each block
    }

    printf("\nEnter the size of the processes:\n");
    for (int i = 0; i < numProcesses; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &processSizes[i]);
        processAllocated[i] = -1; // Set process as unallocated
    }

    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numBlocks; j++) {
            if (blockMemory[j] >= processSizes[i] && !blockAllocated[j]) {
                blockAllocated[j] = 1; // Mark block as allocated
                processAllocated[i] = j; // Allocate process to block j
                blockMemory[j] -= processSizes[i]; // Update block memory
                break;
            }
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock No.\tBlock Size\tFragment\n");
    for (int i = 0; i < numProcesses; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSizes[i]);
        if (processAllocated[i] != -1) {
            int blockNo = processAllocated[i] + 1;
            int blockSize = blockSizes[processAllocated[i]];
            int fragment = blockMemory[processAllocated[i]];
            printf("%d\t\t%d\t\t%d\n", blockNo, blockSize, fragment);
        } else {
            printf("Not Allocated\t\t-\t\t-\n");
        }
    }
}

int main() {
    firstFitAllocation();
    return 0;
}
