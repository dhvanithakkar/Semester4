#include <stdio.h>
int tsp_g[10][10] = {
   {999, 10, 15, 20},
   {10, 999, 35, 25},
   {15, 35, 999, 30},
   {20, 25, 30, 999},
   };
int visited[10], n, cost = 0;

void travellingsalesman(int c){
   int k, adj_vertex = 999;
   int min = 999;
   
   visited[c] = 1;
   
   printf("%d ", c + 1);
   
   for(k = 0; k < n; k++) {
      if((tsp_g[c][k] != 0) && (visited[k] == 0)) {
         if(tsp_g[c][k] < min) {
            min = tsp_g[c][k];
         }
         adj_vertex = k;
      }
   }
   if(min != 999) {
      cost = cost + min;
   }
   if(adj_vertex == 999) {
      adj_vertex = 0;
      printf("%d", adj_vertex + 1);
      cost = cost + tsp_g[c][adj_vertex];
      return;
   }
   travellingsalesman(adj_vertex);
}

int main(){
   int i, j;
   n = 4;
   for(i = 0; i < n; i++) {
      visited[i] = 0;
   }
   printf("Shortest Path: ");
   travellingsalesman(0);
   printf("\nMinimum Cost: ");
   printf("%d\n", cost);
   return 0;
}
