class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        vector<int> res;
        sort(nums.begin(), nums.end());
        for (int x : nums)
            res.push_back(x);
        return res;
    }
};