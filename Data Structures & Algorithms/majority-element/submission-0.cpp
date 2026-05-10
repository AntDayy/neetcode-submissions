class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            ans[nums[i]]++;
        }
        int count = 0;
        int save;
        for (auto x : ans)
        {
            if (x.second > count)
            {
                count = x.second;
                save = x.first;
            }
        }
        return save;
    }
};