#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#define no_pro 5
#define no_res 3

// struct process {
//     int pid;
//     int max_need[NO_RES];
//     int allocated[NO_RES];
//     int need[NO_RES];
//     bool completed;
// };

int main()
{
    
    printf("Enter number of processes: ");
    //scanf("%d", &n_pro);

    // printf("Enter number of resources: ");
    // int no_res;
    // scanf("%d", &n_res);

    //int available[n_pro][NO_RES];
    int available[no_pro+1][no_res] = {{3, 3, 2}, {0, 0, 0}, {0, 0, 0},{0, 0, 0},{0, 0, 0},{0, 0, 0}};

    int avail_i = 0;
    // struct process *p = (struct process *)malloc(n_pro * sizeof(struct process));

    // printf("Enter Available Resources for: \n");
    // for(int i = 0; i < NO_RES; i++)
    // {
    //     printf("Resource %d: \n", (i+1));
    //     scanf("%d", &available[avail_i][i]);
    // }
    
    int allocated[no_pro][no_res] = {0,1,0, 2,0,0, 3,0,2, 2,1,1, 0,0,2};
    int max_need[no_pro][no_res] = {7,5,3, 3,2,2, 9,0,2, 2,2,2, 4,3,3};
    int need[no_pro][no_res];
    bool completed[no_pro];
    
    for(int i = 0; i < no_pro; i++){
        // p[i].pid = i+1;
        // printf("P[%d]\n", i+1);
        // printf("Enter Max Need for: \n");
        // for(int j=0; j< NO_RES; j++)
        // {
        //     printf("Resource %d: \n", (j+1));
        //     scanf("%d", &p[i].max_need[j]);
        // }
        
        // printf("Enter Allocated Resources for: \n");
        for(int j=0; j < no_res; j++)
        {
        //     printf("Resource %d: \n", (j+1));
        //     scanf("%d", &p[i].allocated[j]);

            need[i][j] = max_need[i][j] - allocated[i][j];
        }
        completed[i] = false;
    }

    printf("\n");
    int completedProcesses = 0, currentProcess = 0;
    printf("Safe sequence: \n<");
    for (int k = 0; k < no_pro; k++) {
        for (int currentProcess = 0; currentProcess < no_pro; currentProcess++) {
            if (!completed[currentProcess]) {
 
                bool foundProcess = true;
                for (int j = 0; j < no_res; j++) {
                    if (need[currentProcess][j] > available[avail_i][j]){
                        foundProcess = false;
                        break;
                    }
                }
 
                if (foundProcess) {
                    avail_i ++;
                    for (int y = 0; y < no_res; y++)
                    {
                        available[avail_i][y] = available[avail_i-1][y] + allocated[currentProcess][y];
                        // printf(" %d->%d ", available[avail_i-1][y], available[avail_i][y]);
                    }
                    printf("P(%d), ", currentProcess);

                    completed[currentProcess] = true;
                }
            }
        }
    }
   
    bool safe = true;
       
    for(int i=0;i<no_pro;i++)
    {
      if(!completed[i])
      {
        safe = false;
         printf("The following system is not safe");
         break;
      }
    }
     
     if(safe)
    {
        
        printf("\b\b>");
        // Print process details in table format
        printf("\n\nProcess Details:\n");
        printf("Process\t| Allocation \t\t| Max Need\t\t| Need\t\t\t| Available");
        
        for (int i = 0; i < no_pro; i++)
        {
            printf("\nP[%d]\t| ", i);
            for(int j = 0; j<no_res; j++)
            {
                printf("\t%d", allocated[i][j]);
            }
            printf("| ");
            for(int j = 0; j<no_res; j++)
            {
                printf("\t%d", max_need[i][j]);
            }
            printf("|");
            for(int j = 0; j<no_res; j++)
            {
                printf("\t%d", need[i][j]);
            }
            printf("|");
            for(int j = 0; j<no_res; j++)
            {
                printf("\t%d", available[i][j]);
            }
        
        }
        printf("\n\n");
        for(int j = 0; j<no_res; j++)
        {
                printf("%d\t", available[no_pro][j]);
        }

    }
    return 0;
}
