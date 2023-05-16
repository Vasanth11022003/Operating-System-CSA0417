#include <stdio.h>

#define BLOCK_SIZE 8192 // 8 KB
#define POINTER_SIZE 4 // 4 bytes

#define DIRECT_BLOCKS 12
#define SINGLE_INDIRECT_BLOCKS (BLOCK_SIZE / POINTER_SIZE)
#define DOUBLE_INDIRECT_BLOCKS (SINGLE_INDIRECT_BLOCKS * SINGLE_INDIRECT_BLOCKS)
#define TRIPLE_INDIRECT_BLOCKS (SINGLE_INDIRECT_BLOCKS * DOUBLE_INDIRECT_BLOCKS)

#define TOTAL_BLOCKS (DIRECT_BLOCKS + SINGLE_INDIRECT_BLOCKS + DOUBLE_INDIRECT_BLOCKS + TRIPLE_INDIRECT_BLOCKS)

int main() {
    int maxFileSize;
    int requiredBlocks;
    int totalInodeSize = 0;

    printf("Enter the required file size in bytes: ");
    scanf("%d", &maxFileSize);

  
    requiredBlocks = maxFileSize / BLOCK_SIZE;
    if (maxFileSize % BLOCK_SIZE != 0)
        requiredBlocks++;

 
    totalInodeSize += sizeof(int) * DIRECT_BLOCKS; 
    totalInodeSize += sizeof(int); 
    totalInodeSize += sizeof(int) * SINGLE_INDIRECT_BLOCKS; 
    totalInodeSize += sizeof(int); 
    totalInodeSize += sizeof(int) * SINGLE_INDIRECT_BLOCKS * SINGLE_INDIRECT_BLOCKS; 
    totalInodeSize += sizeof(int); 
    totalInodeSize += sizeof(int) * SINGLE_INDIRECT_BLOCKS * DOUBLE_INDIRECT_BLOCKS; 

    int maxFileSizeAllowed = (TOTAL_BLOCKS - totalInodeSize) * BLOCK_SIZE;

    printf("Maximum file size that can be stored in this file system: %d bytes\n", maxFileSizeAllowed);

    return 0;
}

