#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

// Number of vertices in the graph
#define V 5

// A utility function to find the vertex with minimum
// distance value, from the set of vertices not yet included
// in shortest path tree
int minDistance(int dist[], bool sptSet[])
{
  // Initialize min value
  int min = INT_MAX, min_index;

  for (int v = 0; v < V; v++)
    if (sptSet[v] == false && dist[v] <= min)
      min = dist[v], min_index = v;

  return min_index;
}

// A utility function to print the constructed distance
// array
void printSolution(int dist[])
{
  printf("Vertex \t\t Distance from Source\n");
  for (int i = 0; i < V; i++)
    printf("%d \t\t\t\t %d\n", i, dist[i]);
}

// Function that implements Dijkstra's single source
// shortest path algorithm for a graph represented using
// adjacency matrix representation
void dijkstra(int graph[V][V], int src)
{
  int dist[V]; // The output array. dist[i] will hold the
               // shortest
  // distance from src to i

  bool sptSet[V]; // sptSet[i] will be true if vertex i is
                  // included in shortest
  // path tree or shortest distance from src to i is
  // finalized

  // Initialize all distances as INFINITE and stpSet[] as
  // false
  for (int i = 0; i < V; i++)
    dist[i] = INT_MAX, sptSet[i] = false;

  // Distance of source vertex from itself is always 0
  dist[src] = 0;

  // Find shortest path for all vertices
  for (int count = 0; count < V - 1; count++)
  {
    // Pick the minimum distance vertex from the set of
    // vertices not yet processed. u is always equal to
    // src in the first iteration.
    int u = minDistance(dist, sptSet);

    // Mark the picked vertex as processed
    sptSet[u] = true;

    // Update dist value of the adjacent vertices of the
    // picked vertex.
    for (int v = 0; v < V; v++)

      // Update dist[v] only if is not in sptSet,
      // there is an edge from u to v, and total
      // weight of path from src to v through u is
      // smaller than current value of dist[v]
      if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
        dist[v] = dist[u] + graph[u][v];
  }

  // print the constructed distance array
  printSolution(dist);
}
void createGraph(int v, int graph[v][v])
{
  printf("Please provide edge weight to connect and 0 to disconnect:\n");
  int i, j;
  for (i = 0; i < v; i += 1)
  {
    for (j = 0; j < v; j += 1)
    {
      printf("Is there an edge between %d and %d? (edge weight/0) : ", i, j);
      scanf("%d", &graph[i][j]);
    }
  }
}
// driver's code
int main()
{
  /* Let us create the example graph discussed above */
  /* int graph[V][V] = {{0, 2, 0, 6, 0},
                      {2, 0, 3, 8, 5},
                      {0, 3, 0, 0, 7},
                      {6, 8, 0, 0, 9},
                      {0, 5, 7, 9, 0}};*/
  int v;
  printf("Enter the number of vertices: ");
  scanf("%d", &v);
  int graph[v][v];
  createGraph(v, graph);

  // Function call
  dijkstra(graph, 0);

  return 0;
}