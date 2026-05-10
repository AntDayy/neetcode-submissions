class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        int max = -1;
        for (int i = 0; i < n; i++)
        {
            if (heights[i] > max)
                max = heights[i];
        }
        int h = 0;
        int largest = 0;
        while (h <= max)
        {
            h++;
            int wid = 0;
            int best_with = 0;
            for (int i = 0; i < n; i++)
            {
                if (heights[i] >= h)
                    wid++;
                else
                    wid = 0;
                if (wid > best_with)
                    best_with = wid;
            }
            int a = best_with * h;
            if (a > largest)
                largest = a;
        }
        return largest;
    }
};