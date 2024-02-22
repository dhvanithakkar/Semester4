#include <stdio.h>

int main()
{
    int n;
    printf ("Enter number of jobs:");
    scanf ("%d", &n);
    
    int start[n], end[n], jobNo[n];
    int jobsDone = 1;
    
    for (int i = 0; i < n; i++)
	{
        printf ("Enter start time of Job %d:   ", (i + 1));
        scanf ("%d", &start[i]);
        printf ("Enter end time of Job %d  :   ", (i + 1));
        scanf ("%d", &end[i]);
        jobNo[i] = i+1;
	}
	
	for (int i = 0; i < n; i++)
	{
        for (int j = 0; j < n - i - 1; j++)
        {
            if (end[j] > end[j + 1])
            {
                int temp = end[j];
                end[j] = end[j + 1];
                end[j + 1] = temp;
                
                temp = start[j];
                start[j] = start[j + 1];
                start[j + 1] = temp;
                
                temp = jobNo[j];
                jobNo[j] = jobNo[j + 1];
                jobNo[j + 1] = temp;
                
            }
        }
	}
	printf("\nJob %d done from %d to %d", jobNo[0], start[0], end[0]);
	int currentTime = end[0];
	for(int i=1; i<n; i++)
	{
	    if(start[i] >= currentTime)
	    {
	        printf("\nJob %d done from %d to %d", jobNo[i], start[i], end[i]);
	        jobsDone += 1;
	        currentTime = end[i];
	    }
	}
	printf("\nTotal Jobs done: %d", jobsDone);
	return 0;
}
