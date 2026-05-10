class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int i = 0; i < nums.size(); i++)
            count[nums[i]]++;
        for (auto const& [key, val] : count)
        {
            if (val >= 2)
                return true;
        }
        return false;
    }
};