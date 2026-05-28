class Solution
{
public:
    bool sameBinaryTree(TreeNode *q, TreeNode *p)
    {
        stack<TreeNode *> s1, s2;
        s1.push(q);
        s2.push(p);

        while (!s1.empty() && !s2.empty())
        {
            TreeNode *cur1 = s1.top();
            s1.pop();
            TreeNode *cur2 = s2.top();
            s2.pop();

            if (cur1 == nullptr && cur2 == nullptr)
                continue;

            if (cur1 == nullptr || cur2 == nullptr || cur1->val != cur2->val)
                return false;

            s1.push(cur1->left);
            s1.push(cur1->right);
            s2.push(cur2->left);
            s2.push(cur2->right);
        }

        return s1.empty() && s2.empty();
    }

    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (root == nullptr)
            return false;

        if (root->val == subRoot->val)
        {
            if (sameBinaryTree(root, subRoot))
                return true;
        }

        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};