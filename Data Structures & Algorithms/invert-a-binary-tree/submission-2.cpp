class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == nullptr)
            return nullptr;

        TreeNode *cur = root->left;
        root->left = root->right;
        root->right = cur;

        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};