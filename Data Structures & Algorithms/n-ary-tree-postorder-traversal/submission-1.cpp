class Solution
{
public:
    void postOrder(Node *root, vector<int> &res)
    {
        if (!root->children.empty())
        {
            for (auto c : root->children)
            {
                postOrder(c, res);
            }
        }
        res.push_back(root->val);
    }

    vector<int> postorder(Node *root)
    {
        if (!root)
            return {};
        vector<int> res;
        postOrder(root, res);
        return res;
    }
};