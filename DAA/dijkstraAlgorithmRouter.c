#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
 
#define V 15

int minDistance(int dist[], bool sptSet[], int n)
{
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < n; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
 
    return min_index;
}
void printRouterPath(int parent[], int src)
{
    if(src == -1)
    return;
    
    printRouterPath(parent, parent[src]);
    printf("\t%d", src);
}
 
void printSolution(int dist[], int parent[], int n)
{
    printf("Vertex \t\t Distance from Source \t\t Parent Node\n");
    int max_bw = dist[0];
    int max_bw_router = 0;
    for (int i = 0; i < n; i++)
    {
        printf("%d \t\t\t %d \t\t\t\t %d\n", i, dist[i], parent[i]);
        if(dist[i]>max_bw)
        {
            max_bw = dist[i];
            max_bw_router = i;
        }
    }
    printf("Maximum bandwidth possible is: %d\n", max_bw);
    printf("Path of maximum bandwidth is:\n");
    printRouterPath(parent, max_bw_router);
}
 
void dijkstra(int graph[V][V], int src, int n)
{
    int dist[n];
 
    bool sptSet[n]; 
    int parent[n];
    
    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX, sptSet[i] = false, parent[i] = -1;
 
    dist[src] = 0;
 
    for (int count = 0; count < n - 1; count++) 
    {
        int u = minDistance(dist, sptSet, n);
 
        sptSet[u] = true;
 
        for (int v = 0; v < n; v++)
 
            if (!sptSet[v] && graph[u][v]
                && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
    }
 
    // print the constructed distance array
    printSolution(dist, parent, n);
}
 
int main()
{
    // int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
    //                     { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
    //                     { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
    //                     { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
    //                     { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
    //                     { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
    //                     { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
    //                     { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
    //                     { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
    int n, src;
    printf("Enter number of vertices in router graph: \n");
    scanf("%d", &n);
    // int n = 9, src;
    // int graph[V][V] = {
    //                     {0, 10, 0, 20, 0, 0},
    //                     {10, 0, 30, 5, 0, 0},
    //                     {0, 30, 0, 0, 15, 0},
    //                     {20, 5, 0, 0, 10, 30},
    //                     {0, 0, 15, 10, 0, 5},
    //                     {0, 0, 0, 30, 5, 0}};

    int graph[V][V];
    for(int i=0; i<n; i++)
    {
        printf("Enter graph edge weights of row %d:\n", i);
        for(int j=0; j<n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    
    printf("Enter number of source router: \n");
    scanf("%d", &src);

    dijkstra(graph, src, n);
 
    return 0;
}
