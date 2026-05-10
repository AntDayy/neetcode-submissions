class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        vector<int> res;
        int left = 0;
        int right = numbers.size() - 1;
        while (left <= right)
        {
            if (numbers[left] + numbers[right] < target)
                left++;
            else if (numbers[left] + numbers[right] > target)
                right--;
            else
            {
                res.push_back(++left);
                res.push_back(++right);
                break;
            }
        }
        return res;
    }
};