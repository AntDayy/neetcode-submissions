class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        vector<int> maxleft(n), maxright(n);
        int left = 0;
        int right = n - 1;
        int ml = 0, mr = 0;

        while (left <= n && right >= 0)
        {
            if (left == 0 && right == n - 1)
            {
                maxleft[left++] = 0;
                maxright[right--] = 0;
                continue;
            }
            if (height[left - 1] > ml)
                ml = height[left - 1];
            if (height[right + 1] > mr)
                mr = height[right + 1];
            maxleft[left++] = ml;
            maxright[right--] = mr;
        }

        int water = 0;
        for (int i = 0; i < n; i++)
        {
            int t = min(maxleft[i], maxright[i]) - height[i];
            if (t > 0)
                water += t;
        }
        return water;
    }
};