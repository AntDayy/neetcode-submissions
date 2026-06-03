class Solution
{
public:
    void f(TreeNode *root, int k, int &res, int &n)
    {
        if (root == nullptr)
            return;

        f(root->left, k, res, n);
        n++;
        if (n == k)
        {
            res = root->val;
            return;
        }
        f(root->right, k, res, n);
    }

    int kthSmallest(TreeNode *root, int k)
    {
        int res = 0;
        int n = 0;
        f(root, k, res, n);
        return res;
    }
};