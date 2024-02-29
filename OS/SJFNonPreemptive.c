#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct process {
    int pid;
    int arrivalTime;
    int burstTime;
    int turnAroundTime;
    int completionTime;
    int waitingTime;
    int responseTime;
    bool completed;
};
void sort(struct process *p, int n);
void main()
{
    printf("Enter number of processes: ");
    int n;
    scanf("%d", &n);
    struct process *p = (struct process *)malloc(n * sizeof(struct process));
    for(int i = 0; i < n; i++){
        p[i].pid = i+1;
        printf("P[%d]\n", i+1);
        printf("Enter arrival time :");
        scanf("%d", &p[i].arrivalTime);
        printf("Enter burst time :");
        scanf("%d", &p[i].burstTime);
        p[i].completed = false;                        

    }
    printf("\n");
    int currentTime = 0, completedProcesses = 0;
    float totalWaitingTime = 0, totalTurnaroundTime = 0;
    printf("Process\t| Arrival Time\t| Burst Time\t| Completion Time\t| Turnaround Time\t| Waiting Time\n");
    while (completedProcesses < n)
    {
        int shortestBurstIndex = -1;
        int shortestBurst = INT_MAX; 

        for (int i = 0; i < n; i++)
        {
            if (!p[i].completed && p[i].arrivalTime <= currentTime && p[i].burstTime < shortestBurst)
            {
                shortestBurst = p[i].burstTime;
                shortestBurstIndex = i;
            }
        }

        if (shortestBurstIndex == -1)
        {
            printf(" Idle (%d) |", currentTime);
            currentTime++;
            continue; // No process available to execute
        }

        // Update current time and process details

        currentTime += p[shortestBurstIndex].burstTime;
        p[shortestBurstIndex].completionTime = currentTime;
        p[shortestBurstIndex].turnAroundTime = p[shortestBurstIndex].completionTime - p[shortestBurstIndex].arrivalTime;
        p[shortestBurstIndex].waitingTime = p[shortestBurstIndex].turnAroundTime - p[shortestBurstIndex].burstTime;

        // Update total waiting and turnaround time
        totalWaitingTime += p[shortestBurstIndex].waitingTime;
        totalTurnaroundTime += p[shortestBurstIndex].turnAroundTime;

        // Mark the process as completed
        p[shortestBurstIndex].completed = true;
        completedProcesses++;
        
        printf("P[%d]\t|\t%d\t|\t%d\t|\t%d\t\t|\t%d\t\t|\t%d\n", p[shortestBurstIndex].pid,
               p[shortestBurstIndex].arrivalTime, p[shortestBurstIndex].burstTime,
               p[shortestBurstIndex].completionTime, p[shortestBurstIndex].turnAroundTime, p[shortestBurstIndex].waitingTime);
        p[shortestBurstIndex].burstTime = 0;
    }

    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(p[j].completionTime > p[j + 1].completionTime)
            {
                struct process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }


    printf("\n\nGantt Chart:\n");    
    for (int i = 0; i < n; i++) 
    {
        printf(" P%d (%d)|", p[i].pid, p[i].completionTime);
    }
    printf("\n");


    printf("\n");

    // Calculate and print average waiting time and average turnaround time
    float avg_waiting_time = totalWaitingTime / n;
    float avg_turnaround_time = totalTurnaroundTime / n;

    printf("\nAverage Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);

}

void sort(struct process *p, int n){
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(p[j].arrivalTime > p[j + 1].arrivalTime)
            {
                struct process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}
