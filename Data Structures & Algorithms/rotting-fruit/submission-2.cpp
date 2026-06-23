class Solution
{
private:
    int d1[4] = {-1, 0, 0, 1};
    int d2[4] = {0, -1, 1, 0};

public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        queue<pair<int, int>> q;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 1)
                    grid[i][j] = -1;
                if (grid[i][j] == 2)
                {
                    grid[i][j] = -2;
                    q.push({i, j});
                }
                if (grid[i][j] == 0)
                    grid[i][j] = -3;
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
                if (r >= 0 && r < grid.size() && c >= 0 && c < grid[r].size() && grid[r][c] == -1)
                {
                    if (grid[i][j] == -2)
                        grid[r][c] = 1;
                    else
                        grid[r][c] = grid[i][j] + 1;
                    q.push({r, c});
                }
            }
        }

        int max = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] > max)
                    max = grid[i][j];
                if (grid[i][j] == -1)
                    return -1;
            }
        }

        return max;
    }
};