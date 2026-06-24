class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> res;
        vector<vector<int>> learn(numCourses);
        vector<int> indegree(numCourses, 0);

        for (auto pre : prerequisites)
        {
            int course = pre[0];
            int pre_course = pre[1];
            learn[pre_course].push_back(course);
            indegree[course]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            res.push_back(cur);

            for (int neighbor : learn[cur])
            {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        if (res.size() == numCourses)
            return res;
        return {};
    }
};