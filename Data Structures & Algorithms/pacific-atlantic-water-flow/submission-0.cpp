class Solution
{
private:
    int d1[4] = {-1, 0, 0, 1};
    int d2[4] = {0, -1, 1, 0};

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> res;
        vector<vector<bool>> parafic(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));

        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                for (int j = 0; j < m; j++)
                {
                    q.push({i, j});
                    parafic[i][j] = true;
                }
            }
            else
            {
                parafic[i][0] = true;
                q.push({i, 0});
            }
        }

        while (!q.empty())
        {
            pair<int, int> cur = q.front();
            q.pop();
            int i = cur.first;
            int j = cur.second;

            for (int k = 0; k < 4; k++)
            {
                int r = i + d1[k];
                int c = j + d2[k];

                if (r >= 0 && r < n && c >= 0 && c < m && parafic[r][c] == false && heights[r][c] >= heights[i][j])
                {
                    parafic[r][c] = true;
                    q.push({r, c});
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (i == n - 1)
            {
                for (int j = 0; j < m; j++)
                {
                    q.push({i, j});
                    atlantic[i][j] = true;
                }
            }
            else
            {
                q.push({i, m - 1});
                atlantic[i][m - 1] = true;
            }
        }

        while (!q.empty())
        {
            pair<int, int> cur = q.front();
            q.pop();
            int i = cur.first;
            int j = cur.second;

            for (int k = 0; k < 4; k++)
            {
                int r = i + d1[k];
                int c = j + d2[k];

                if (r >= 0 && r < n && c >= 0 && c < m && atlantic[r][c] == false && heights[r][c] >= heights[i][j])
                {
                    atlantic[r][c] = true;
                    q.push({r, c});
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (parafic[i][j] && atlantic[i][j])
                    res.push_back({i, j});
            }
        }

        return res;
    }
};