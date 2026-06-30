class Solution
{
public:
    int openLock(vector<string> &deadends, string target)
    {
        if (target == "0000")
            return 0;

        unordered_set<string> visited;
        for (auto s : deadends)
            visited.insert(s);
        if (visited.find("0000") != visited.end())
            return -1;
        visited.insert("0000");

        queue<pair<string, int>> q;
        q.push({"0000", 0});

        while (!q.empty())
        {
            auto [pass, step] = q.front();
            q.pop();

            if (pass == target)
                return step;

            for (int i = 0; i < 4; i++)
            {
                string up = pass;
                string down = pass;

                up[i] = (up[i] == '9') ? '0' : up[i] + 1;
                down[i] = (down[i] == '0') ? '9' : down[i] - 1;

                if (visited.find(up) == visited.end())
                {
                    visited.insert(up);
                    q.push({up, step + 1});
                }

                if (visited.find(down) == visited.end())
                {
                    visited.insert(down);
                    q.push({down, step + 1});
                }
            }
        }
        return -1;
    }
};