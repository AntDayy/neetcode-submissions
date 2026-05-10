class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        vector<int> res;
        unordered_map<int, int> dem;
        for (auto &x : nums)
            dem[x]++;
        int cnt = 0, savekey;
        while (cnt < k)
        {
            int savevalue = 0;
            for (auto &x : dem)
            {
                if (x.second > savevalue)
                {
                    savevalue = x.second;
                    savekey = x.first;
                }
            }
            res.push_back(savekey);
            dem[savekey] = 0;
            ++cnt;
        }
        return res;
    }
};