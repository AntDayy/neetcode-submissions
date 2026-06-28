class Solution
{
public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (!root)
            return root;

        if (key < root->val)
            root->left = deleteNode(root->left, key);
        else if (key > root->val)
            root->right = deleteNode(root->right, key);
        else
        {
            if (!root->left)
                return root->right;
            if (!root->right)
                return root->left;

            TreeNode *cur = root->left;
            while (cur->right)
                cur = cur->right;
            root->val = cur->val;
            root->left = deleteNode(root->left, root->val);
        }

        return root;
    }
};