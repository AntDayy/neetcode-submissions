class Solution
{
public:
    void dfs(int i, vector<bool> &visited, vector<vector<int>> &adj)
    {
        visited[i] = true;
        for (int x : adj[i])
        {
            if (!visited[x])
                dfs(x, visited, adj);
        }
    }

    int countComponents(int n, vector<vector<int>> &edges)
    {
        int res = 0;
        vector<bool> visited(n, false);
        vector<vector<int>> adj(n);

        for (auto e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                res++;
                dfs(i, visited, adj);
            }
        }

        return res;
    }
};