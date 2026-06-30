class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        vector<vector<bool>> believe(n + 1, vector<bool>(n + 1, false));
        for (auto t : trust)
            believe[t[0]][t[1]] = true;

        int judge = 0;
        for (int i = 1; i < n + 1; i++)
        {
            int c = 0;
            for (int j = 1; j < n + 1; j++)
            {
                if (believe[j][i] == true)
                {
                    c++;
                    if (c == n - 1)
                    {
                        judge = i;
                        break;
                    }
                }
            }
            if (judge == i)
                break;
        }

        if (judge == 0)
            return -1;

        for (int i = 1; i < n + 1; i++)
        {
            if (believe[judge][i] == true)
                return -1;
        }

        return judge;
    }
};