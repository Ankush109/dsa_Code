class Solution
{
public:
    bool isdirectedcycle(int i, vector<int> adj[], int vis[], int dfsvis[])
    {
        vis[i] = 1;
        dfsvis[i] = 1;
        for (auto it : adj[i])
        {
            if (!vis[it])
            {
                if (isdirectedcycle(it, adj, vis, dfsvis))
                {
                    return true;
                }
            }
            else if (dfsvis[it])
            {
                return true;
            }
        }
        dfsvis[i] = 0;
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
    {
        int vis[V];
        int dfsvis[V];
        memset(vis, 0, sizeof vis);
        memset(dfsvis, 0, sizeof dfsvis);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (isdirectedcycle(i, adj, vis, dfsvis))
                {
                    return true;
                }
            }
        }
        return false;
    }
};
