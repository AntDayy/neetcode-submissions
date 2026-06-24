class Solution
{
private:
    vector<int> parent;
    vector<int> size;

    int find(int v)
    {
        if (v == parent[v])
            return v;
        return parent[v] = find(parent[v]);
    }

    void unionSets(int a, int b)
    {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        vector<int> res(2);
        int n = edges.size();
        parent.resize(n + 1);
        size.resize(n + 1);

        for (int i = 0; i <= n; i++)
            parent[i] = i;

        for (auto x : edges)
        {
            int a = find(x[0]);
            int b = find(x[1]);

            if (a == b)
            {
                res[0] = x[0];
                res[1] = x[1];
            }
            else
            {
                unionSets(a, b);
            }
        }

        return res;
    }
};