class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            int n = target - nums[i];
            if (map.find(n) != map.end())
                return {map[n], i};
            map[nums[i]] = i;
        }
        return {};
    }
};
