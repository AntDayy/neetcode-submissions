class Solution
{
public:
    void f(TreeNode *root, long long min, long long max, bool &check)
    {
        if (root == nullptr)
            return;
        if (!(root->val > min && root->val < max))
        {
            check = false;
            return;
        }
        f(root->left, min, root->val, check);
        f(root->right, root->val, max, check);
    }

    bool isValidBST(TreeNode *root)
    {
        bool check = true;
        f(root, -99999999, 99999999, check);
        return check;
    }
};