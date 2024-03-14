#include <stdio.h>
#include <limits.h>
int main ()
{
    int n;
    printf ("Enter number of matrices to be multiplied:");
    scanf ("%d", &n);
    int cost[n][n], k_taken[n][n];
    int r, c;
    
    printf ("Enter number of rows of matrix 1:");
    scanf ("%d", &r);
    printf ("Enter number of columns of matrix 1:");
    scanf ("%d", &c);
    
    int d[n+1];
    d[0] = r;
    d[1] = c;
    
    for (int i = 1; i < n; i++)
	{
        // printf ("Enter number of rows of matrix %d:", (i + 1));
        // scanf ("%d", &r);
        // while(r!=d[i])
        // {
        //     printf ("Not possible. Re-enter number of rows of matrix %d:", (i + 1));
        //     scanf ("%d", &r);
        // }
        printf ("Enter number of columns of matrix %d:", (i + 1));
        scanf ("%d", &c);
        d[i+1] = c;
	}
	
	for(int i=0; i<n; i++)
	{
	    for(int j = 0; j<n; j++)
	    {
	        cost[i][j] = 0;
	        k_taken[i][j] = 0;
	    }
	}
	
	for(int a = 1; a<n; a++)
	{
    	for(int i=0; i<n-a; i++)
    	{
    	    int j = i+a;
    	    
    	    int min = INT_MAX;
    	    
    	    //i=0, j=3
    	    for(int k = i; k < j; k++)
    	    {
    	        int cost_k = cost[i][k] + cost[k+1][j] + d[i]*d[k+1]*d[j+1];
    	        
    	        if(cost_k < min)
    	        {
    	            k_taken[i][j] = k+1;
    	            min = cost_k;
    	        }
    	    }
    	    if(min != INT_MAX)
    	        cost[i][j] = min;
    	    else
    	        cost[i][j] = -1;
    	    
    	}
	}
    printf("cost:\n");
	for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%d     ", cost[i][j]);
        }
        printf("\n");
    }
    printf("k_taken:\n");
	for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%d     ", k_taken[i][j]);
        }
        printf("\n");
    }
	return 0;
	
}
