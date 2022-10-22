//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void findtopo(int i, vector<int> &vis, vector<int> adj[], stack<int> &s)
    {
        vis[i] = 1;
        for (auto it : adj[i])
        {
            if (!vis[it])
            {
                findtopo(it, vis, adj, s);
            }
        }
        s.push(i);
    }
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        stack<int> s;
        vector<int> ans;
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (vis[i] == 0)
            {
                findtopo(i, vis, adj, s);
            }
        }
        while (!s.empty())
        {
            int node = s.top();
            ans.push_back(node);
            s.pop();
        }
        return ans;
    }
};

//{ Dri