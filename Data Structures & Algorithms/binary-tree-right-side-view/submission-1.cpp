class Solution
{
public:
    void f(TreeNode *root, int &k, vector<int> &res, int d)
    {
        if (root == nullptr)
            return;

        if (d >= k)
        {
            res.push_back(root->val);
            k++;
        }

        f(root->right, k, res, d + 1);
        f(root->left, k, res, d + 1);
    }

    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> res;
        int k = 0;
        f(root, k, res, 0);
        return res;
    }
};