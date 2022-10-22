int parent[10000];
int rank[10000];
void make_set()
{
    for (int i = 0; i <= n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}
// 7 -> 6->4->3
int findpar(int node)
{
    if (node == parent[node]) // if the node is equal to the parent
    {
        return node;
    }
    return parent[node] = findpar(parent[node]); // for compressing the path
}
// union
void union(int u, int v)
{
    u = findpar(u);
    v = findpar(v);
    if (rank[u] > rank[v])
    {
        parent[u] = v;
    }
    else if (rank[u] < rank[v])
    {
        parent[v] = u;
    }
    else
    {
        parent[v] = u;
        rank[u]++; // level or height will only increase if the rank are same
    }
}
void main()
{
    make_set();
    int m;
    cin >> m;
    while (m--)
    {
        int u, v;
        union(u, v);
    }
    if (findpar(2) != findpar(3))
    {
        cout << "different component";
    }
    else
    {
        cout << "same component"
    }
}