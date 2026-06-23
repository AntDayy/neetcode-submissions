class Solution
{
private:
    int d1[4] = {-1, 0, 0, 1};
    int d2[4] = {0, -1, 1, 0};

public:
    void islandsAndTreasure(vector<vector<int>> &grid)
    {
        queue<pair<int, int>> q;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
                if (grid[i][j] == 0)
                    q.push({i, j});
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

                if (r >= 0 && r < grid.size() && c >= 0 && c < grid[r].size() && grid[r][c] == 2147483647)
                {
                    grid[r][c] = grid[i][j] + 1;
                    q.push({r, c});
                }
            }
        }

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
                cout << grid[i][j] << " ";
            cout << endl;
        }
    }
};