class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        stack<TreeNode *> s1, s2;
        s1.push(p);
        s2.push(q);

        while (!s1.empty() && !s2.empty())
        {
            TreeNode *cur1 = s1.top();
            TreeNode *cur2 = s2.top();

            s1.pop();
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
};