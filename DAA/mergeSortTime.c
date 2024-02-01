// C program for Merge Sort 
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

int arr[1050];

void merge(int l, int m, int r) 
{ 
	int i, j, k; 
	int n1 = m - l + 1; 
	int n2 = r - m; 

	int L[n1], R[n2]; 

	for (i = 0; i < n1; i++) 
		L[i] = arr[l + i]; 
	for (j = 0; j < n2; j++) 
		R[j] = arr[m + 1 + j]; 

	i = 0; 

	j = 0; 

	k = l; 
	while (i < n1 && j < n2) { 
		if (L[i] <= R[j]) { 
			arr[k] = L[i]; 
			i++; 
		} 
		else { 
			arr[k] = R[j]; 
			j++; 
		} 
		k++; 
	} 

	while (i < n1) { 
		arr[k] = L[i]; 
		i++; 
		k++; 
	} 

	while (j < n2) { 
		arr[k] = R[j]; 
		j++; 
		k++; 
	} 
} 
void mergeSort(int l, int r) 
{ 
	if (l < r) { 
		int m = l + (r - l) / 2; 

		mergeSort(l, m); 
		mergeSort(m + 1, r); 

		merge(l, m, r); 
	} 
} 
void printArray(int A[], int size) 
{ 
	int i; 
	for (i = 0; i < size; i++) 
		printf("%d ", A[i]); 
	printf("\n"); 
} 

// Driver code 
int main() 
{ 
    int time;
    clock_t start, end;
    
    for(int i=0; i<1000; i++)
    {
        long int no = rand();
        arr[i] = no;
    }
    
    
	int arr_size = sizeof(arr) / sizeof(arr[0]); 

	
    start = clock();
	
	mergeSort(0, arr_size - 1); 
	
	end = clock();
	
	time = end-start;
	
	printf("\nTime is: %d", time);
	return 0; 
}
 // APPROX 110- 210 in online programiz compiler
