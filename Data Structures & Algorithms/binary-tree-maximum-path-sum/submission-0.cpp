class Solution
{
public:
    int f(TreeNode *root, int &res)
    {
        if (!root)
            return 0;

        int left = max(f(root->left, res), 0);
        int right = max(f(root->right, res), 0);
        int m = left + right + root->val;
        res = max(m, res);
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode *root)
    {
        int res = -99999999;
        f(root, res);
        return res;
    }
};