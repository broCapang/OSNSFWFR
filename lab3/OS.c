#include <stdio.h>
#include <string.h>

#define MAX_FILES 100     // maximum number of files in the file system
#define MAX_BLOCKS 1000   // maximum number of blocks in the file system
#define BLOCK_SIZE 1024   // size of each block in bytes
#define MAX_FILENAME 100  // maximum length of a file name

// structure to store file information
typedef struct {
    char name[MAX_FILENAME];
    int start_block;
    int num_blocks;
} file_t;

// function to allocate blocks sequentially
int allocate_blocks(int num_blocks, int start_block, int *allocated_blocks, int *free_blocks) {
    int i;

    // find first free block
    for (i = start_block; i < start_block+num_blocks+1; i++) {
        if (free_blocks[i] == 0) {
            return -1;
        }
    }


    // allocate the requested number of blocks
    for (i = 0; i < num_blocks; i++) {
        if (start_block + i >= MAX_BLOCKS || free_blocks[start_block + i] == 0) {
            // if there are no more free blocks or a block is already allocated, free the previously allocated blocks and return error
            int j;
            for (j = 0; j < i; j++) {
                free_blocks[start_block + j] = 1;
                allocated_blocks[start_block + j] = 0;
            }
            return -1;
        } else {
            // mark block as allocated
            allocated_blocks[start_block + i] = 1;
            free_blocks[start_block + i] = 0;
        }
    }

    // return the starting block of the allocated blocks
    return start_block;
}

// function to search for a file
void search_file(file_t *files, int num_files, int *allocated_blocks) {
    char name[MAX_FILENAME];
    printf("Enter the name of the file to search for: ");
    scanf("%s", name);

    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(name, files[i].name) == 0) {
            printf("File name: %s\n", files[i].name);
            printf("Starting block: %d\n", files[i].start_block);
            printf("Number of blocks: %d\n", files[i].num_blocks);
            printf("Occupied blocks: ");
            int j;
            for (j = 0; j < files[i].num_blocks; j++) {
                if (allocated_blocks[files[i].start_block + j] == 1) {
                    printf("%d ", files[i].start_block + j);
                }
            }
            printf("\n");
            return;
        }
    }

    printf("File not found.\n");
}

int main() {
    file_t files[MAX_FILES];
    int num_files, allocated_blocks[MAX_BLOCKS], free_blocks[MAX_BLOCKS];
    int i;

    // initialize free blocks array
    for (i = 0; i < MAX_BLOCKS; i++) {
        free_blocks[i] = 1;
    }

    // get number of files from user
    printf("Enter number of files: ");
    scanf("%d", &num_files);

    // get file information from user and allocate blocks for each file
    for (i = 0; i < num_files; i++) {
        printf("Enter information for file %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", files[i].name);
        printf("Starting block: ");
        scanf("%d", &files[i].start_block);
        printf("Number of blocks: ");
        scanf("%d", &files[i].num_blocks);
        int test = allocate_blocks(files[i].num_blocks,files[i].start_block, allocated_blocks, free_blocks);
        if (test == -1)
        {
            printf("Error: not enough free blocks to allocate file.\n");
        }
        
    }

    // search for file
    search_file(files, num_files, allocated_blocks);

    return 0;
}
