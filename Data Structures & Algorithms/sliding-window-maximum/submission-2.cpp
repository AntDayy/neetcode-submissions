class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        if (nums.empty() || k == 0)
            return {};

        vector<int> result;
        int current_max = nums[0];
        int max_idx = 0;

        for (int i = 1; i < k; i++)
        {
            if (nums[i] >= current_max)
            {
                current_max = nums[i];
                max_idx = i;
            }
        }
        result.push_back(current_max);

        for (int i = 1; i <= nums.size() - k; i++)
        {
            int new_element_idx = i + k - 1;
            int new_element = nums[new_element_idx];

            if (max_idx < i)
            {
                current_max = nums[i];
                max_idx = i;
                for (int j = i + 1; j <= new_element_idx; j++)
                {
                    if (nums[j] >= current_max)
                    {
                        current_max = nums[j];
                        max_idx = j;
                    }
                }
            }
            else if (new_element >= current_max)
            {
                current_max = new_element;
                max_idx = new_element_idx;
            }
            result.push_back(current_max);
        }

        return result;
    }
};