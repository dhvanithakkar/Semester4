#include <math.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

int arr[10000];

void swap(int *xp, int *yp) 
{ 
	int temp = *xp; 
	*xp = *yp; 
	*yp = temp; 
} 

void selectionSort(int n) 
{ 
	int i, j, min_idx; 

	for (i = 0; i < n-1; i++) 
	{ 
		min_idx = i; 
		for (j = i+1; j < n; j++) 
		if (arr[j] < arr[min_idx]) 
			min_idx = j; 

		if(min_idx != i) 
			swap(&arr[min_idx], &arr[i]); 
	} 
} 

void printArray(int arr[], int size) 
{ 
	int i; 
	for (i=0; i < size; i++) 
		printf("%d ", arr[i]); 
	printf("\n"); 
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

	
    start = clock();
	
	selectionSort(arr_size);
	
	end = clock();
	
	time = end-start;
	
	printf("\nTime is: %d", time);
	return 0; 
}
// 59494 - 135824: ts10000
