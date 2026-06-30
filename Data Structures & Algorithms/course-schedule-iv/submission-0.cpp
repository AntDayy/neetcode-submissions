class Solution
{
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>> &prerequisites, vector<vector<int>> &queries)
    {
        vector<bool> res;
        unordered_map<int, vector<int>> learn;
        for (auto pre : prerequisites)
            learn[pre[1]].push_back(pre[0]);

        for (auto que : queries)
        {
            bool check = false;
            queue<int> q;
            unordered_set<int> visited;

            q.push(que[1]);
            while (!q.empty())
            {
                int c = q.front();
                q.pop();
                visited.insert(c);

                if (c == que[0])
                {
                    check = true;
                    break;
                }

                for (int l : learn[c])
                {
                    if (visited.find(l) == visited.end())
                        q.push(l);
                }
            }

            res.push_back(check);
        }

        return res;
    }
};