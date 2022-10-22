class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist_to(V, INT_MAX);
        dist_to[S] = 0;
        pq.push({0, S});
        while (!pq.empty())
        {
            int dist = pq.top().first;  // this is the distance
            int prev = pq.top().second; // the prev node
            pq.pop();

            for (auto it : adj[prev])
            {
                int next = it[0];
                int nextdist = it[1];
                if (dist_to[next] > dist_to[prev] + nextdist)
                {
                    dist_to[next] = dist_to[prev] + nextdist;
                    pq.push({dist_to[next], next});
                }
            }
        }
        return dist_to;