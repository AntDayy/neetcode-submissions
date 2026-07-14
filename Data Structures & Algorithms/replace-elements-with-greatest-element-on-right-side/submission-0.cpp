class Solution
{
public:
    vector<int> replaceElements(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> res(n, -1);

        int max = -1e9;
        for (int i = n - 2; i >= 0; i--)
        {
            if (arr[i + 1] > max)
                max = arr[i + 1];
            res[i] = max;
        }

        return res;
    }
};