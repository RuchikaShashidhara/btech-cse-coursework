// Implementation of Best Fit Algorithm for Memory Management

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct process {
        char process_name[1];
        int  process_size;
};
typedef struct process Process;

struct block {
        int block_size;
        int fragment_size;
        char process_name[1];
};
typedef struct block Block;

int comparator(const void *b1, const void *b2);

void allocate_process(Block *blocks, int num_blocks, Process *processes, int num_process);

void display_allocation(Block *blocks, int num_blocks);

int main() {

        int num_blocks, num_process;
        
        printf("\n Enter the number of memory segments: ");
        scanf("%d", &num_blocks);
        
        Block *blocks = (Block *) malloc (sizeof(Block) * num_blocks);
        
        for(int i = 0; i < num_blocks; i++) {
                printf("\n Enter partition size: ");
                scanf("%d", &blocks[i].block_size);
                blocks[i].fragment_size = blocks[i].block_size;
        }
        
        printf("\n\n Enter the number of processes to assign the memory: ");
        scanf("%d", &num_process);
        
        Process *processes = (Process *) malloc (sizeof(Process) * num_process);
        
        for(int i = 0; i < num_process; i++) {
                printf("\n Enter the name of the process: ");
                scanf("%s", processes[i].process_name);
                printf(" Enter the size of the process: ");
                scanf("%d", &processes[i].process_size);
        }
        
        allocate_process(blocks, num_blocks, processes, num_process);
        
        qsort(blocks, num_blocks, sizeof(Block), comparator);
        
        display_allocation(blocks, num_blocks);
        
        printf("\n");
        return 0;
}

int comparator(const void *b1, const void *b2) {
        Block* bl1 = (Block *) b1;
        Block* bl2 = (Block *) b2;        
        return (bl1 -> block_size) - (bl2 -> block_size);
}

void allocate_process(Block *blocks, int num_blocks, Process *processes, int num_process) {

        for (int ps = 0; ps < num_process; ps++) {

                int size_diff = INT_MAX;
                int b_num, b_diff;
                
                for (int b = 0; b < num_blocks; b++) {
                        
                        int size_curr = blocks[b].fragment_size - processes[ps].process_size;
                        if (size_curr >= 0 && size_curr <= size_diff) {
                                size_diff = size_curr;
                                b_num = b;
                                b_diff = size_curr;
                        }                                
                }
                
                blocks[b_num].fragment_size = b_diff;
                blocks[b_num].process_name[0] = processes[ps].process_name[0];
        }
}

void display_allocation(Block *blocks, int num_blocks) {

        printf("\n\n Partition No\tPartition Size\tPartition Status\tFragment Size\n");
        for (int i = 0; i < num_blocks; i++) {
        
                printf(" %d\t\t%d\t\t", i, blocks[i].block_size);
                
                if (blocks[i].fragment_size != blocks[i].block_size) 
                        printf("allocated<%s>\t\t%d\n", blocks[i].process_name, blocks[i].fragment_size);
                
                else 
                        printf("free\n");

        }
}
