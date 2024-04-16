#include <stdio.h>
#include <stdbool.h>
void main()//worst_fit(int processes[], int num_processes, int memory[], int num_memory) 
{
    int processes[] = {212, 417, 112, 426};
    int num_processes = sizeof(processes) / sizeof(processes[0]); 
    int memory[] = {100, 500, 200, 300, 600};
    int num_memory = sizeof(memory) / sizeof(memory[0]); 
    double total_memory = 0.0;
    for (int i = 0; i < num_memory; i++) {
        total_memory += memory[i];
    }

    int memory_pairs[num_memory][2]; // Store memory block index and size
    for (int i = 0; i < num_memory; i++) {
        memory_pairs[i][0] = i;
        memory_pairs[i][1] = memory[i];
    }

    // Sorting memory blocks by size using simple selection sort
    for (int i = 0; i < num_memory - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < num_memory; j++) {
            if (memory_pairs[j][1] > memory_pairs[min_idx][1]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            int temp_idx = memory_pairs[i][0];
            int temp_size = memory_pairs[i][1];
            memory_pairs[i][0] = memory_pairs[min_idx][0];
            memory_pairs[i][1] = memory_pairs[min_idx][1];
            memory_pairs[min_idx][0] = temp_idx;
            memory_pairs[min_idx][1] = temp_size;
        }
    }

    bool mem_filled[num_memory];
    for (int i = 0; i < num_memory; i++) {
        mem_filled[i] = false;
    }

    int memory_used = 0;
    bool allocated;

    printf("\nWorst Fit: \n");
    printf("PNo.\tPSize\tBNo.\tBSize\n");
    for (int at_process = 0; at_process < num_processes; at_process++) {
        int process = processes[at_process];
        allocated = false;
        for (int at_memory = 0; at_memory < num_memory; at_memory++) {
            int mem_index = memory_pairs[at_memory][0];
            int block = memory_pairs[at_memory][1];
            if (process <= block && !mem_filled[at_memory]) {
                memory_used += process;
                mem_filled[at_memory] = true;
                printf("%d\t\t%d\t\t%d\t\t%d\n", at_process + 1, process, mem_index, block);
                allocated = true;
                break;
            }
        }

        if (!allocated) {
            printf("%d\t\t%d\t\tNOT ALLOCATED\n", at_process + 1, process);
        }
    }
    printf("Efficiency = %.2f%%\n", (double)memory_used / total_memory * 100);
}
