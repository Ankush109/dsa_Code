#include <stdio.h>
#include <stdlib.h>

int find(int P[], int i)
{
    while (P[i] != i)
        i = P[i];
    return i;
}
void union1(int P[], int i, int j)
{
    int a = find(P, i);
    int b = find(P, j);
    P[a] = b;
}
void kruskal(int V, int G[V][V])
{
    int i, j, P[V], sum = 0, edge_no = 0, x, y, min;
    for (i = 0; i < V; i++)
        P[i] = i;
    while (edge_no < V - 1)
    {
        min = INT_MAX;
        x = 0;
        y = 0;
        for (i = 0; i < V; i++)
        {
            for (j = 0; j < V; j++)
            {
                if (find(P, i) != find(P, j) && G[i][j] < min)
                {
                    min = G[i][j];
                    x = i;
                    y = j;
                }
            }
        }
        union1(P, x, y);
        printf("Edge from %d to %d Cost :- %d\n", x, y, G[x][y]);
        sum += G[x][y];
        edge_no++;
    }
    printf("Minimum cost of spanning tree :- %d", sum);
}

int main()
{

    /* int Graph[5][5] = {{0, 2, 0, 6, 0},
                      {2, 0, 3, 8, 5},
                      {0, 3, 0, 0, 7},
                      {6, 8, 0, 0, 9},
                      {0, 5, 7, 9, 0}};*/

    int V;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    int G[V][V];

    printf("\nEnter the adjacency matrix:\n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            scanf("%d", &G[i][j]);
            if (G[i][j] == 0)
                G[i][j] = INT_MAX;
        }
    }

    kruskal(V, G);
    return 0;
    //  print(n);
}