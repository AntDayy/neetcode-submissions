class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int left = 1, right = -1;

        for (int i = 0; i < piles.size(); i++)
            right = max(piles[i], right);

        int res = right;

        while (left <= right)
        {
            int m = left + ((right - left) / 2);
            long long total = 0;

            for (int &pile : piles)
                total += (pile - 1) / m + 1;
            if (total <= h)
            {
                right = m - 1;
                res = m;
            }
            else
                left = m + 1;
        }

        return res;
    }
};