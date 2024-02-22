#include <stdio.h>
int main ()
{
    int n;
    float capacity;
    printf ("Enter weight capacity of bag:");
    scanf ("%f", &capacity);
    printf ("Enter number of fruits you see:");
    scanf ("%d", &n);
    
    int weight[n], value[n];
    float ratio[n];
    float totalValue=0.0;

    for (int i = 0; i < n; i++)
	{
        printf ("Enter weight of fruit %d:                ", (i + 1));
        scanf ("%d", &weight[i]);
        printf ("Enter nutritional value of fruit %d:     ", (i + 1));
        scanf ("%d", &value[i]);
        ratio[i] = (float)value[i] /(float) weight[i];
	}
	for (int i = 0; i < n; i++)
	{
        for (int j = 0; j < n - i - 1; j++)
        {
            if (ratio[j] < ratio[j + 1])
            {
                int temp = weight[j];
                weight[j] = weight[j + 1];
                weight[j + 1] = temp;
                
                temp = value[j];
                value[j] = value[j + 1];
                value[j + 1] = temp;
                
                float tempf = ratio[j];
                ratio[j] = ratio[j + 1];
                ratio[j + 1] = tempf;
            }
        }
	}
	for(int i=0; i<n; i++)
	{
	    if(capacity >= weight[i])
	    {
	        capacity = capacity - weight[i];
	        totalValue += value[i];
	    }
	    else if(capacity > 0)
	    {
	        totalValue += value[i] * capacity / weight[i];
	        capacity = 0;
	    }
	}
	printf("Maximum nutritional value achievable is: %f", totalValue);
	return 0;
}
