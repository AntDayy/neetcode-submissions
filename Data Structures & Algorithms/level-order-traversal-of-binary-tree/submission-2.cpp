/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    void f(TreeNode *root, int k, vector<vector<int>> &res){
        if (root == nullptr) return;

        if (k >= res.size()) {
            vector<int> a;
            res.push_back(a);}
        res[k].push_back(root->val);

        f(root->left, k + 1, res);
        f(root->right, k + 1, res);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        f(root, 0, res);
        return res;
    }
};
