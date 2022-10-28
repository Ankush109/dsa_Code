#include <stdio.h>
#include <stdlib.h>

void DFS(int v, int s, int graph[v][v], int vis[v])
{
    printf("%d ", s);
    vis[s] = 1;
    for (int j = 0; j < v; j++)
    {
        if (graph[s][j] == 1 && !vis[j])
        {
            DFS(v, j, graph, vis);
        }
    }
}

int main()
{

    printf("enter the number of vertices");
    int v;
    scanf("%d", &v);
    int graph[v][v];
    // vis
    int vis[v];
    for (int i = 0; i < v; i++)
    {
        vis[i] = 0;
    }

    // take user input for graph connection
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            printf("Is there an edge between %d and %d? (1/0): ", i, j);
            scanf("%d", &graph[i][j]);
        }
    }
    int s = 0;
    printf("enter the starting index of dfs traversal");
    scanf("%d", &s);
    // print the graph
    printf("The graph is:");
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            printf("%d  ", graph[i][j]);
        }
        printf("\n");
    }

    DFS(v, s, graph, vis);
    return 0;
}