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
    int remainingTime;
    bool completed;
};

void main()
{
    printf("Enter number of processes: ");
    int n, timeQuantum;
    
    scanf("%d", &n);
    printf("Enter Time quantum: ");    
    scanf("%d", &timeQuantum);
    struct process *p = (struct process *)malloc(n * sizeof(struct process));
    for(int i = 0; i < n; i++){
        p[i].pid = i+1;
        printf("P[%d]\n", i+1);
        printf("Enter arrival time :");
        scanf("%d", &p[i].arrivalTime);
        printf("Enter burst time :");
        scanf("%d", &p[i].burstTime);
        p[i].remainingTime = p[i].burstTime; 
        p[i].completed = false;                        

    }
    printf("\n");
    int currentTime = 0, completedProcesses = 0, currentProcess = 0;
    float totalWaitingTime = 0, totalTurnaroundTime = 0, totalCompletionTime = 0;
    
    printf("\n\nGantt Chart:\n");
    printf("|");
    while (completedProcesses < n)
    {
        for(int i=0; i<n; i++)
        {
            if(!p[currentProcess].completed && p[currentProcess].arrivalTime<=currentTime)
            {
                break;
            }
            //picks the next ready incomplete process, and if none are found, idle state.
            currentProcess++;
            if(currentProcess == n)
                currentProcess = 0;
            if(i==n-1)
            {
                currentTime += timeQuantum;
                i = 0;
                printf("IDLE(%d)|", currentTime);
            }
        }

        if(p[currentProcess].remainingTime < timeQuantum)
        {
            // If the process needs lesser time to complete than the time quantum, only time required by it is given to it.
            currentTime += p[currentProcess].remainingTime;
            p[currentProcess].remainingTime = 0;
            p[currentProcess].completed = true;
        }
        else
        {        
            // Update current time and process details
            p[currentProcess].remainingTime-= timeQuantum;
            currentTime += timeQuantum;
        }
        

        if (p[currentProcess].remainingTime == 0)
        {
            // Process has completed execution
            p[currentProcess].completionTime = currentTime;
            p[currentProcess].turnAroundTime = p[currentProcess].completionTime - p[currentProcess].arrivalTime;
            p[currentProcess].waitingTime = p[currentProcess].turnAroundTime - p[currentProcess].burstTime;

            // Update total waiting and turnaround time
            totalCompletionTime += p[currentProcess].completionTime;
            totalWaitingTime += p[currentProcess].waitingTime;
            totalTurnaroundTime += p[currentProcess].turnAroundTime;

            // Mark the process as completed
            p[currentProcess].completed = true;
            completedProcesses++;
        }

        // Print process in Gantt chart format
        printf(" P%d (%d) |", p[currentProcess].pid, currentTime);
        
        currentProcess++;
        if(currentProcess == n)
            currentProcess = 0;
    }

    printf("\n");

    // Print process details in table format
    printf("\n\nProcess Details:\n");
    printf("Process\t| Arrival Time\t| Burst Time\t| Completion Time\t| Turnaround Time\t| Waiting Time\n");

    for (int i = 0; i < n; i++)
    {
        printf("P[%d]\t|\t%d\t|\t%d\t|\t%d\t\t|\t%d\t\t|\t%d\n", p[i].pid,
               p[i].arrivalTime, p[i].burstTime,
               p[i].completionTime, p[i].turnAroundTime, p[i].waitingTime);
    }

    // Calculate and print average waiting time and average turnaround time
    float avg_waiting_time = totalWaitingTime / n;
    float avg_turnaround_time = totalTurnaroundTime / n;
    float avg_completion_time = totalCompletionTime / n;

    printf("\nAverage Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Completion Time: %.2f\n", avg_completion_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);

}
