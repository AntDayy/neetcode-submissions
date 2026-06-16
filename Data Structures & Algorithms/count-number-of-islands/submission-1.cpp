class Solution
{
private:
    int d1[4] = {1, 0, 0, -1};
    int d2[4] = {0, 1, -1, 0};

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int count = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    grid[i][j] = '0';
                    dfs(grid, i, j);
                    ++count;
                }
            }
        }
        return count;
    }

    void dfs(vector<vector<char>> &grid, int i, int j)
    {
        for (int k = 0; k < 4; k++)
        {
            int r = i + d1[k];
            int c = j + d2[k];

            if (r >= 0 && r < grid.size() && c >= 0 && c < grid[i].size() && grid[r][c] == '1')
            {
                grid[r][c] = '0';
                dfs(grid, r, c);
            }
        }
    }
};