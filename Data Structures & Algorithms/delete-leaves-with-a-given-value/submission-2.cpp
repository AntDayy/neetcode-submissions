class Solution
{
public:
    void deletePostOrder(TreeNode *&root, int target)
    {
        if (!root)
            return;

        deletePostOrder(root->left, target);
        deletePostOrder(root->right, target);

        if (root->val == target && !root->left && !root->right)
            root = nullptr;
    }

    TreeNode *removeLeafNodes(TreeNode *root, int target)
    {
        deletePostOrder(root, target);
        return root;
    }
};