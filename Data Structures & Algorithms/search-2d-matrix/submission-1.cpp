class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix.empty() || matrix[0].empty())
            return false;

        int above = 0;
        int below = matrix.size() - 1;
        int save_row;

        while (above <= below)
        {
            int m = above + ((below - above) / 2);

            if (target >= matrix[m][0] && target <= matrix[m].back())
            {
                save_row = m;
                break;
            }
            else if (target < matrix[m][0])
                below = m - 1;
            else
                above = m + 1;
        }

        int left = 0, right = matrix[save_row].size() - 1;

        while (left <= right)
        {
            int m = left + ((right - left) / 2);
            if (matrix[save_row][m] < target)
                left = m + 1;
            else if (matrix[save_row][m] > target)
                right = m - 1;
            else
                return true;
        }

        return false;
    }
};