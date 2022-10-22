void dfsbridge(int node, int parent, vector<int> &vis, vector<int> &tim, vector<int> &low, int timer, vector<int> adj[])
{
    vis[node] = 1;
    tim[node] = low[node] = timer++;
    for (auto it : adj[node])
    {
        if (it == parent)
            continue;
        if (!vis[it])
        {
            dfsbridge(it, node, vis, tim, lowm, timer, adj);
            low[node] = min(low[node], low[it]);
            if (low[it] > tin[node])
            {
                cout << node << " " << it << endl;
            }
            else
            {
                low[node] = min(low[node], tin[it]);`
            }
        }
    }
}