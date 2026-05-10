class Solution
{
public:
    int maxArea(vector<int> &heights)
    {
        int most = 0;
        int left = 0;
        int right = heights.size() - 1;
        while (left <= right)
        {
            int water = (right - left) * min(heights[right], heights[left]);
            if (water > most)
                most = water;
            if (heights[left] > heights[right])
                right--;
            else
                left++;
        }
        return most;
    }
};