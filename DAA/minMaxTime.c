#include <stdio.h>  
#include <time.h>  
#include <stdlib.h>  

int arr[10000];

int min, max;

void minMax(int l, int r)
{
    int max1, min1, mid;
    if (l == r)
    {
        max = min = arr[l];
    }
    else
    {
        if (l == r - 1)
        {
            if (arr[l] < arr[r])
            {
                min = arr[l];
                max = arr[r];
            }
            else
            {
                min = arr[r];
                max = arr[l];
            }
        }
        else
        {
            mid = (l + r)/2;
            minMax(l, mid);
            max1 = max;
            min1 = min;
            
            minMax(mid+1, r);
            
            if (max<max1)
                max = max1;
            if (min>min1)
                min = min1;
        }
        
        
    }
}
int main() 
{ 
    int time;
    clock_t start, end;
    
    for(int i=0; i<10000; i++)
    {
        long int no = rand();
        arr[i] = no;
    }
    
    
	int arr_size = sizeof(arr) / sizeof(arr[0]); 

	min = arr[0];
	max = arr[0];
	
    start = clock();
	
	minMax(0, arr_size); 
	
	end = clock();
	
	printf("\nMin: %d", min);
	printf("\nMax: %d", max);
	
	time = end-start;
	
	printf("\nTime is: %d", time);
	return 0; 
}
// 116, 182 ts10000
