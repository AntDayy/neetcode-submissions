class Solution
{
public:
    void f(TreeNode *root, int low, int high, int &sum)
    {
        if (root == nullptr)
            return;

        if (root->val >= low && root->val <= high)
            sum += root->val;
        f(root->left, low, high, sum);
        f(root->right, low, high, sum);
    }

    int rangeSumBST(TreeNode *root, int low, int high)
    {
        int res = 0;
        f(root, low, high, res);
        return res;
    }
};