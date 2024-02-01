#include <stdio.h>  
#include <time.h>  
#include <stdlib.h>  

int n = 10000;
int arr[10000];

void swap(int* a, int* b) {  
    int t = *a;  
    *a = *b;  
    *b = t;  
}  
int partition(int low, int high) {  
    int pivot = arr[high];  
    int i = (low - 1);  
  
    for (int j = low; j <= high - 1; j++) 
    {  
        if (arr[j] < pivot) 
        {  
            i++;  
            swap(&arr[i], &arr[j]);  
        }  
    }  
    swap(&arr[i + 1], &arr[high]);  
    return (i + 1);  
}  
void quickSort(int low, int high) 
{  
    if (low < high) {  
        int pi = partition(low, high);  
        quickSort(low, pi - 1);  
        quickSort(pi + 1, high);  
    }  
}   
void printArray(int size) 
{  
    int i;  
    for (i = 0; i < size; i++)  
        printf("%d ", arr[i]);  
    printf("\n");  
}  
  
int main() 
{  
    int time;
    clock_t start, end;
    // long int no = rand();
    // for(int i=0; i<n; i++)
    // {
    //     arr[i] = no + i;
    // }
    
    for(int i=0; i<10000; i++)
    {
        long int no = rand();
        arr[i] = no;
    }
  
    int n = sizeof(arr) / sizeof(arr[0]);
    
    start = clock();
	
    quickSort(0, n - 1);  
	
	end = clock();
	
	time = end-start;
	
	printf("\nTime is: %d", time);
    return 0;  
}  

// random: 800-1500 ts10000
// sorted: 200000-300000 ts10000
