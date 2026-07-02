class Solution
{
private:
    struct edge
    {
        int v;
        int w;
    };

public:
    unordered_map<int, int> shortestPath(int n, vector<vector<int>> &edges, int src)
    {
        unordered_map<int, int> res;
        vector<long long> dist(n, 2e9);
        unordered_map<int, vector<edge>> adj;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        dist[src] = 0;
        q.push({src, 0});

        for (auto c : edges)
        {
            edge canh;
            canh.v = c[1];
            canh.w = c[2];
            adj[c[0]].push_back(canh);
        }

        while (!q.empty())
        {
            auto cur = q.top();
            q.pop();

            int u = cur.first;
            int weight = cur.second;

            if (dist[u] < weight)
                continue;

            for (auto x : adj[u])
            {
                int d = x.v;
                int k = x.w;
                if (dist[d] > dist[u] + k)
                {
                    dist[d] = dist[u] + k;
                    q.push({d, dist[d]});
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (dist[i] == 2e9)
                dist[i] = -1;
            res.insert({i, dist[i]});
        }

        return res;
    }
};