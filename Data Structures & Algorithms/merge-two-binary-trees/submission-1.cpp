class Solution
{
public:
    void merge(TreeNode *&root, TreeNode *root1, TreeNode *root2)
    {
        if (!root1 && !root2)
            return;
        if (!root1)
        {
            root = root2;
            return;
        }
        if (!root2)
        {
            root = root1;
            return;
        }

        root = new TreeNode(root1->val + root2->val);

        merge(root->left, root1->left, root2->left);
        merge(root->right, root1->right, root2->right);
    }

    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        if (!root1 && !root2)
            return nullptr;
        if (!root1)
            return root2;
        if (!root2)
            return root1;

        TreeNode *root;
        merge(root, root1, root2);
        return root;
    }
};