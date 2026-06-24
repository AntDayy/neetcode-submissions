class Solution
{
private:
    int d1[4] = {-1, 0, 0, 1};
    int d2[4] = {0, -1, 1, 0};

public:
    void dfs(vector<vector<char>> &board, vector<vector<bool>> &check, int i, int j)
    {
        for (int k = 0; k < 4; k++)
        {
            int r = i + d1[k];
            int c = j + d2[k];

            if (r >= 0 && r < board.size() && c >= 0 && c < board[r].size() && board[r][c] == 'O' && check[r][c] == false)
            {
                check[r][c] = true;
                dfs(board, check, r, c);
            }
        }
    }

    void solve(vector<vector<char>> &board)
    {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> check(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++)
        {
            if (i == 0 || i == n - 1)
            {
                for (int j = 0; j < m; j++)
                {
                    if (board[i][j] == 'O')
                    {
                        check[i][j] = true;
                        dfs(board, check, i, j);
                    }
                }
            }
            else
            {
                if (board[i][0] == 'O')
                {
                    check[i][0] = true;
                    dfs(board, check, i, 0);
                }
                if (board[i][m - 1] == 'O')
                {
                    check[i][m - 1] = true;
                    dfs(board, check, i, m - 1);
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 'O' && check[i][j] == false)
                    board[i][j] = 'X';
            }
        }
    }
};