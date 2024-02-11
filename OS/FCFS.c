#include <stdio.h>
#include <stdlib.h>

struct process {
    int pid;
    int arrivalTime;
    int burstTime;
    int turnAroundTime;
    int completionTime;
    int waitingTime;
    int responseTime;
};
void sort(struct process *p, int n);
void findWaitingCompletionTurnAroundTime(struct process *p, int n);
float avgWaitingTime(struct process *p, int n);
float avgTurnaroundTime(struct process *p, int n);
float avgCompletionTime(struct process *p, int n);
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
    }
    printf("\n");
    sort(p, n);
    findWaitingCompletionTurnAroundTime(p, n);
    printf("\nProcess\t\tAT\tBT\tCT\tTAT\tWT");
    for(int i=0;i<n;i++)
    {
        printf("\nP[%d]\t\t%d\t%d\t%d\t%d\t%d", p[i].pid, p[i].arrivalTime, p[i].burstTime, p[i].completionTime, p[i].turnAroundTime, p[i].waitingTime);
    }
    float CoT= avgCompletionTime(p, n);
    float TaT = avgTurnaroundTime(p, n);
    float WaT = avgWaitingTime(p, n);
    
    printf("\nAverage turnaround time = %f\n", TaT);
    printf("Average waiting time = %f\n", WaT);
    printf("Average completion time = %f\n", CoT);
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
int max(int a, int b)
{
    if(a > b)
    return a;
    else
    return b;
}
void findWaitingCompletionTurnAroundTime(struct process *p, int n) 
{ 
    p[0].waitingTime = 0;
    p[0].turnAroundTime = p[0].burstTime;
    p[0].completionTime = p[0].burstTime;
    
    for (int  i = 1; i < n ; i++ ) 
    {
        // old completion time, arrival time max: 
        int start_at = max(p[i-1].completionTime, p[i].arrivalTime);
        p[i].completionTime = start_at + p[i].burstTime;
        p[i].turnAroundTime =  p[i].completionTime - p[i].arrivalTime; 
        p[i].waitingTime = p[i].turnAroundTime - p[i].burstTime;
    }
} 

float avgWaitingTime(struct process *p, int n){
    float sum = 0.0;
    for(int i = 0; i < n; i++){
        sum += p[i].waitingTime;
    }
    return sum / n;
}
float avgCompletionTime(struct process *p, int n){
    float sum = 0.0;
    for(int i = 0; i < n; i++){
        sum += p[i].completionTime;
    }
    return sum / n;
}

float avgTurnaroundTime(struct process *p, int n){
    float sum = 0.0;
    for(int i = 0; i < n; i++){
        sum += p[i].turnAroundTime;
    }
    return sum / n;
}