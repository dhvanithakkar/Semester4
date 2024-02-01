#include <math.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

int arr[10000];

void insertionSort(int n)
{
	int i, key, j;
	for (i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

void printArray(int A[], int size) 
{ 
	int i; 
	for (i = 0; i < size; i++) 
		printf("%d ", A[i]); 
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
	
	insertionSort(arr_size);
	
	end = clock();
	
	time = end-start;
	
	printf("\nTime is: %d", time);
	return 0; 
}
// 33466 - 58748: ts10000
