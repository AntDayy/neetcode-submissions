class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> output;
        int i = 0, j = 0, n = 1;
        while (1)
        {
            if (j == nums.size())
                break;
            if (i < nums.size())
            {
                if (i != j)
                    n *= nums[i];
                ++i;
            }
            else
            {
                output.push_back(n);
                n = 1;
                i = 0;
                ++j;
            }
        }
        return output;
    }
};