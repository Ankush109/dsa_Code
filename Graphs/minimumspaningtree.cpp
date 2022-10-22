class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        int key[V];

        bool mstset[V];
        for (int i = 0; i < V; i++)
        {
            key[i] = INT_MAX;
            mstset[i] = false;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0, 0});
        key[0] = 0;
        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();
            mstset[u] = true;
            for (auto it : adj[u])
            {
                int v = it[0];
                int weight = it[1];
                if (mstset[v] == false && weight < key[v])
                {

                    key[v] = weight;
                    pq.push({key[v], v});
                }
            }
        }
        int sum = 0;
        for (int i = 0; i < V; i++)
        {

            sum += key[i];
        }
        return sum;
    }
};
