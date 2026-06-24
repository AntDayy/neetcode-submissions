class Solution
{
public:
    bool validTree(int n, vector<vector<int>> &edges)
    {
        vector<bool> visited(n, false);
        vector<vector<int>> e(n);
        queue<pair<int, int>> q;
        q.push({0, -1});
        visited[0] = true;

        for (auto x : edges)
        {
            e[x[0]].push_back(x[1]);
            e[x[1]].push_back(x[0]);
        }

        while (!q.empty())
        {
            pair<int, int> cur = q.front();
            q.pop();
            int u = cur.first;
            int parent = cur.second;

            for (int v : e[u])
            {
                if (!visited[v])
                {
                    visited[v] = true;
                    q.push({v, u});
                }
                else if (v != parent)
                    return false;
            }
        }

        int count = 0;
        for (auto b : visited)
        {
            if (b)
                count++;
        }
        return (count == n) ? true : false;
    }
};