// Kruskal's algorithm in C

#include <stdio.h>

#define MAX 30

typedef struct edge
{
  int u, v, w;
} edge;

typedef struct edge_list
{
  edge data[MAX];
  int n;
} edge_list;

edge_list elist;

// int Graph[MAX][MAX], n;
edge_list spanlist;
// Sorting algo
void sort(int n)
{
  int i, j;
  edge temp;

  for (i = 1; i < elist.n; i++)
    for (j = 0; j < elist.n - 1; j++)
      if (elist.data[j].w > elist.data[j + 1].w)
      {
        temp = elist.data[j];
        elist.data[j] = elist.data[j + 1];
        elist.data[j + 1] = temp;
      }
}
int find(int belongs[], int vertexno)
{
  return (belongs[vertexno]);
}
void applyUnion(int n, int belongs[], int c1, int c2)
{
  int i;

  for (i = 0; i < n; i++)
    if (belongs[i] == c2)
      belongs[i] = c1;
}
// Applying Krushkal Algo
void kruskalAlgo(int n, int Graph[n][n])
{
  int belongs[MAX], i, j, cno1, cno2;
  elist.n = 0;

  for (i = 1; i < n; i++)
    for (j = 0; j < i; j++)
    {
      if (Graph[i][j] != 0)
      {
        elist.data[elist.n].u = i;
        elist.data[elist.n].v = j;
        elist.data[elist.n].w = Graph[i][j];
        elist.n++;
      }
    }

  sort(n);

  for (i = 0; i < n; i++)
    belongs[i] = i;

  spanlist.n = 0;

  for (i = 0; i < elist.n; i++)
  {
    cno1 = find(belongs, elist.data[i].u);
    cno2 = find(belongs, elist.data[i].v);

    if (cno1 != cno2)
    {
      spanlist.data[spanlist.n] = elist.data[i];
      spanlist.n = spanlist.n + 1;
      applyUnion(n, belongs, cno1, cno2);
    }
  }
}

// Printing the result
void print(int n)
{
  int i, cost = 0;

  for (i = 0; i < spanlist.n; i++)
  {
    printf("\n%d - %d : %d", spanlist.data[i].u, spanlist.data[i].v, spanlist.data[i].w);
    cost = cost + spanlist.data[i].w;
  }

  printf("\nSpanning tree cost: %d", cost);
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
int main()
{
  int i, j, total_cost;

  int n = 5;

  /* int Graph[5][5] = {{0, 2, 0, 6, 0},
                      {2, 0, 3, 8, 5},
                      {0, 3, 0, 0, 7},
                      {6, 8, 0, 0, 9},
                      {0, 5, 7, 9, 0}};*/
  int v;
  printf("Enter the number of vertices: ");
  scanf("%d", &v);
  int Graph[v][v];
  createGraph(v, Graph);

  kruskalAlgo(n, Graph);
  print(n);
}