#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define num_requests 7
#define disk_size 199
// Function to sort an array in ascending order
void sort(int arr[], int n) {
 for (int i = 0; i < n - 1; i++) {
 for (int j = 0; j < n - i - 1; j++) {
 if (arr[j] > arr[j + 1]) {
 // Swap arr[j] and arr[j+1]
 int temp = arr[j];
 arr[j] = arr[j + 1];
 arr[j + 1] = temp;
 }
 }
 }
}
// Function to find the index of the next request in SSTF algorithm
int findNextSSTF(int currentPos, int requests[], int n, int visited[]) {
 int minDist = INT_MAX;
 int nextIndex = -1;
 for (int i = 0; i < n; i++) {
 if (!visited[i]) {
 int dist = abs(requests[i] - currentPos);
 if (dist < minDist) {
 minDist = dist;
 nextIndex = i;
 }
 }
 }
 return nextIndex;
}
// FCFS (First Come First Serve) Disk Scheduling Algorithm
int fcfs(int requests[], int n, int initialPos) {
 int totalMoves=0;
 printf("Path: %d ", initialPos);
 for (int i = 0; i < n; i++) {
 totalMoves += abs(requests[i] - initialPos);
 initialPos = requests[i];
 printf("-> %d ", initialPos);
 }
 printf("\n");
 return totalMoves;
}
// SSTF (Shortest Seek Time First) Disk Scheduling Algorithm
int sstf(int requests[], int n, int initialPos) {
 int totalMoves = 0;
 int visited[num_requests] = {0};
 int currentPos = initialPos;
 printf("Path: %d ", currentPos);
 for (int i = 0; i < n; i++) {
 int nextIndex = findNextSSTF(currentPos, requests, n, visited);
 visited[nextIndex] = 1;
 totalMoves += abs(requests[nextIndex] - currentPos);
 currentPos = requests[nextIndex];
 printf("-> %d ", currentPos);
 }
 printf("\n");
 return totalMoves;
}
// SCAN Disk Scheduling Algorithm
int scan(int requests[], int n, int initialPos) {
 int totalMoves = 0;
 int direction = 1; // 1 for moving towards higher cylinder numbers, -1 for moving towards lower cylinder numbers
 sort(requests, n);
 int index = 0;
 // Move to the end of the disk or the last request before the head pointer in the higher direction
 printf("Path: %d ", initialPos);
 for (int i = 0; i < n; i++) {
 if (requests[i] > initialPos) {
 totalMoves += abs(requests[i] - initialPos);
 initialPos = requests[i];
 printf("-> %d ", initialPos);
 }
 else if (requests[i] == initialPos) {
 // If there's a request exactly at the initial position, process it
 totalMoves += abs(requests[i] - initialPos);
 initialPos = requests[i];
 printf("-> %d ", initialPos);
 break;
 }
 }
 // Move to the end of the disk in the higher direction
 totalMoves += abs(disk_size - initialPos);
 printf("-> %d ", disk_size);
 initialPos=disk_size;
 // Move to the last request before the head pointer
 int lastRequestBeforeHead = initialPos;
 while (index < n && requests[index] < initialPos) {
 lastRequestBeforeHead = requests[index];
 index++;
 }
 // Move towards lower cylinder numbers from the last request before the head pointer until the beginning of the disk
 for (int i = index - 1; i >= 0; i--) {
 totalMoves += abs(requests[i] - initialPos);
 initialPos = requests[i];
 printf("-> %d ", initialPos);
 }
 printf("\n");
 return totalMoves;
}
// C-SCAN Disk Scheduling Algorithm
int cscan(int requests[], int n, int initialPos) {
 int totalMoves = 0;
 sort(requests, n);
 int index = 0;
 while (index < n && requests[index] < initialPos) {
 index++;
 }
 printf("Path: %d ", initialPos);
 // Move in one direction until reaching the last request before the head pointer
 for (int i = index; i < n; i++) {
 totalMoves += abs(requests[i] - initialPos);
 initialPos = requests[i];
 printf("-> %d ", initialPos);
 }
 // Move to the end of the disk
 totalMoves += abs(disk_size - initialPos);
 printf("-> %d ", disk_size);
 // Move back to the beginning of the disk
 totalMoves += disk_size;
 printf("-> 0 ");
 initialPos = 0;
 // Move to the last request before the head pointer
 for (int i = 0; i < index; i++) {
 totalMoves += abs(requests[i] - initialPos);
 initialPos = requests[i];
 printf("-> %d ", initialPos);
 }
 printf("\n");
 return totalMoves;
}
// LOOK Disk Scheduling Algorithm
int look(int requests[], int n, int initialPos) {
 int totalMoves = 0;
 int direction = 1; // 1 for moving towards higher cylinder numbers, -1 for lower cylinder numbers
 sort(requests, n);
 int index = 0;
 while (index < n && requests[index] < initialPos) {
 index++;
 }
 if (index == n) {
 direction = -1; // If all requests are lower than initial position, change direction
 index--;
 }
 printf("Path: %d ", initialPos);
 for (int i = index; i >= 0 && i < n; i += direction) {
 totalMoves += abs(requests[i] - initialPos);
 initialPos = requests[i];
 printf("-> %d ", initialPos);
 }
 // Change direction for scanning in the lower direction
 direction = -1;
 // Scan in the lower direction
 for (int i = n - 1; i >= 0; i--) {
 totalMoves += abs(requests[i] - initialPos);
 initialPos = requests[i];
 printf("-> %d ", initialPos);
 }
 printf("\n");
 return totalMoves;
}
int main() {
 int requests[num_requests] = {82, 170, 43, 140, 24, 16, 190}; // Example disk requests
 int initialPos = 50; // Initial position of disk head
 printf("FCFS: Total moves = %d\n\n", fcfs(requests, num_requests, initialPos));
 printf("SSTF: Total moves = %d\n\n", sstf(requests, num_requests, initialPos));
 printf("SCAN: Total moves = %d\n\n", scan(requests, num_requests, initialPos));
 printf("C-SCAN: Total moves = %d\n\n", cscan(requests, num_requests, initialPos));
 printf("LOOK: Total moves = %d\n\n", look(requests, num_requests, initialPos));
 return 0;
} 
