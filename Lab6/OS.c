#include <stdio.h>

#define MAX_PROCESSES 10

int main() {
    int memorySize, pageSize, totalPages, numProcesses;
    int pageTables[MAX_PROCESSES][MAX_PROCESSES];
    int i, j;

    // Step 1: Get input values
    printf("Enter the memory size: ");
    scanf("%d", &memorySize);

    printf("Enter the page size: ");
    scanf("%d", &pageSize);

    totalPages = memorySize / pageSize;

    printf("The no. of pages available in memory are: %d\n", totalPages);

    printf("Enter the number of processes: ");
    scanf("%d", &numProcesses);
    int numPages[numProcesses];
    int currentTotalPages = 0;
    // Step 2: Get page tables for each process
    for (i = 0; i < numProcesses; i++) {
        
        printf("\nEnter the number of pages required for p[%d]: ", i+1);
        scanf("%d", &numPages[i]);
        if (currentTotalPages + numPages[i] > totalPages)
        {
            printf("Error: Not enough pages available in memory for p[%d]!\n", i+1);
            break;
        }
        currentTotalPages += numPages[i];
        
        
        if (numPages[i] > totalPages) {
            printf("Error: Not enough pages available in memory for p[%d]!\n", i+1);
            return 1; // Exit the program with an error code
        }

        printf("Enter the pagetable for p[%d]: ", i+1);

        for (j = 0; j < numPages[i]; j++) {
            scanf("%d", &pageTables[i][j]);

            if (pageTables[i][j] >= totalPages) {
                printf("Error: Invalid page number in pagetable for p[%d]!\n", i+1);
                return 1; // Exit the program with an error code
            }
        }
    }

    // Step 3: Get logical address and find physical address
    int processNo, pageNo, offset;

    printf("\nEnter Logical Address to find Physical Address:\n");
    printf("Enter process no. and page number and offset: ");
    scanf("%d %d %d", &processNo, &pageNo, &offset);
    if (processNo < 1 || processNo > numProcesses) {
        printf("Error: Invalid process number!\n");
        return 1; // Exit the program with an error code
    }

    if (pageNo >= numPages[processNo-1]) {
        printf("Error: Page number doesn't exist in the memory!\n");
        return 1; // Exit the program with an error code
    }

    if (offset >= pageSize) {
        printf("Error: Offset is bigger than the size of one page!\n");
        return 1; // Exit the program with an error code
    }

    // Step 4: Calculate and output the physical address
    int physicalAddress = (pageTables[processNo-1][pageNo] * pageSize) + offset;
    
    printf("The physical address is: %d\n", physicalAddress);

    return 0; // Exit the program successfully
}
