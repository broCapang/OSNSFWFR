#include <stdio.h>

int main() {
    int num_blocks, num_files;
    printf("Enter the number of blocks: ");
    scanf("%d", &num_blocks);
    
    int block_sizes[num_blocks];
    printf("Enter the size of the blocks:\n");
    for (int i = 0; i < num_blocks; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &block_sizes[i]);
    }
    
    printf("Enter the number of files: ");
    scanf("%d", &num_files);
    
    int file_sizes[num_files], allocated_block[num_files];
    int fragment_sizes[num_files];
    for (int i = 0; i < num_files; i++) {
        printf("File %d: ", i + 1);
        scanf("%d", &file_sizes[i]);
        
        int best_block = -1;
        for (int j = 0; j < num_blocks; j++) {
            if (block_sizes[j] >= file_sizes[i]) {
                if (best_block == -1 || block_sizes[j] < block_sizes[best_block]) {
                    best_block = j;
                }
            }
        }
        
        if (best_block != -1) {
            allocated_block[i] = best_block;
            fragment_sizes[i] = block_sizes[best_block] - file_sizes[i];
            block_sizes[best_block] = fragment_sizes[i];
        } else {
            allocated_block[i] = -1;
            fragment_sizes[i] = -1;
        }
    }
    printf("\n");
    printf("File\t\tSize\t\tBlock\t\tFragment\t\tFragment Size\n");
    printf("----\t\t----\t\t-----\t\t--------\t\t-------------\n");
    for (int i = 0; i < num_files; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, file_sizes[i], allocated_block[i] + 1, block_sizes[allocated_block[i]] + file_sizes[i], fragment_sizes[i]);
    }
    
    return 0;
}
