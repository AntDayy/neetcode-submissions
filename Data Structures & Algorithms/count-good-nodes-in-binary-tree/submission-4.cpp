class Solution
{
public:
    void f(TreeNode *root, int k, int &res)
    {
        if (root == nullptr)
            return;
        int n = max(root->val, k);

        f(root->left, n, res);
        if (root->val >= k)
            res++;
        f(root->right, n, res);
    }

    int goodNodes(TreeNode *root)
    {
        int res = 0;
        f(root, root->val, res);
        return res;
    }
};