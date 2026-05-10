class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        vector<vector<int>> s(9, vector<int>(9));
        vector<vector<bool>> rowCheck(9, vector<bool>(10, false));
        vector<vector<bool>> colCheck(9, vector<bool>(10, false));
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                    s[i][j] = 0;
                else
                    s[i][j] = board[i][j] - '0';
            }
        }
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (s[i][j] != 0)
                {
                    if (rowCheck[i][s[i][j]] == true)
                        return false;
                    else
                        rowCheck[i][s[i][j]] = true;
                }
                if (s[j][i] != 0)
                {
                    if (colCheck[i][s[j][i]] == true)
                        return false;
                    else
                        colCheck[i][s[j][i]] = true;
                }
            }
        }
        for (int row = 0; row < 3; row++)
        {
            for (int col = 0; col < 3; col++)
            {
                bool seen[10] = {false};
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        int r = row * 3 + i;
                        int c = col * 3 + j;
                        if (s[r][c] != 0)
                        {
                            if (seen[s[r][c]] == true)
                                return false;
                            else
                                seen[s[r][c]] = true;
                        }
                    }
                }
            }
        }
        return true;
    }
};