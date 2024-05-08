#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void printSolution (int taken[], int arr[], int n);


bool sumOfSubset (int sum, int o_ind, int rem, int arr[], int taken[], int target, int n)
{
    bool ans = false;
    // printf("\n%d: sum, %d: ind, %d:rem, w: %d, tar:%d\n", sum, o_ind, rem, arr[o_ind], target);
    // printf("\n%d\n",  rem - arr[o_ind]);
    if (sum + arr[o_ind] == target)
    {  
        taken[o_ind] = 1;
        // printf("found");

        return true;
    }
    // if(o_ind == n-1)
    // {
    //     return false;
    // }

    if (sum + arr[o_ind] < target && rem - arr[o_ind] >= 0)
    {
        taken[o_ind] = 1;
        ans = sumOfSubset (sum + arr[o_ind], o_ind + 1, rem - arr[o_ind], arr, taken,target, n);
        if(ans)
            return true;
    }
    
    if (sum + rem - arr[o_ind] >= target && sum < target)
    {
        taken[o_ind]=0;
        ans = sumOfSubset (sum, o_ind + 1, rem - arr[o_ind], arr, taken, target, n);
    }
    return ans;
}

int main ()
{
    int arr[] ={1, 9, 7, 5, 18, 12, 20, 15};
    int target = 55;
    int n = sizeof(arr)/sizeof(arr[0]);
    
    int rem = 0;
    int taken[n];
    for(int i = 0; i < n;i++)
    {
        taken[i] = 0;
        rem += arr[i];
    }
    
    bool ans = sumOfSubset (0, 0, rem, arr, taken, target, n);
    
    if(ans)
        printSolution(taken, arr, n);

    else
        printf("No solution");
        
    return 0;
}

void printSolution (int taken[], int arr[], int n)
{
    printf ("\nSolution found.\nFollowing are the taken elements: \n");
    
    for (int i = 0; i < n; i++)
    {
        if(taken[i])
            printf ("%d ", arr[i]);
    }
}
