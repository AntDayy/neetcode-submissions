class Solution
{
private:
    int max_diameter = 0;

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        calculate(root);

        return max_diameter;
    }

    int calculate(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        int left = calculate(root->left);
        int right = calculate(root->right);

        max_diameter = max(max_diameter, left + right);

        return max(left, right) + 1;
    }
};