#include <stdio.h>
#include <stdbool.h>
double sum(int array[]) {
    double total = 0.0;
    int length = sizeof(array) / sizeof(array[0]); 
    for (int i = 0; i < length; i++) {
        total += array[i];
    }
    return total;
}

void main()//first_fit(int processes[], int num_processes, int memory[], int num_memory) 
{
    int processes[] = {212, 417, 112, 426};
    int num_processes = sizeof(processes) / sizeof(processes[0]); 
    int memory[] = {100, 500, 200, 300, 600};
    int num_memory = sizeof(memory) / sizeof(memory[0]); 
    double tot_memory = 0.0;
    bool mem_filled[num_memory];
    for (int i = 0; i < num_memory; i++) {
        tot_memory += memory[i];
        mem_filled[i] = false;
    }

    int memory_used = 0;
    bool allocated;

    printf("\nFirst Fit\n");
    printf("PNo.\tPSize\tBNo.\tBSize\n");
    for (int at_process = 0; at_process < num_processes; at_process++) {
        allocated = false;
        for (int at_memory = 0; at_memory < num_memory; at_memory++) {
            if (processes[at_process] <= memory[at_memory] && !mem_filled[at_memory]) {
                memory_used += processes[at_process];
                mem_filled[at_memory] = true;
                printf("%d\t\t%d\t\t%d\t\t%d\n", at_process + 1, processes[at_process], at_memory, memory[at_memory]);
                allocated = true;
                break;
            }
        }

        if (!allocated) {
            printf("%d\t\t%d\t\tNOT ALLOCATED\n", at_process + 1, processes[at_process]);
        }
    }
    printf("Efficiency = %.2f%\n", (double)memory_used / (tot_memory) * 100);
}



