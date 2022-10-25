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
    vector<vector<int>> findLeaves(TreeNode* root) {
        unordered_map<TreeNode*, int> m;
        vector<vector<int>> ans(100);
        height(root, m, ans);
        vector<vector<int>> ret;
        for(auto &v: ans) {
            if(v.size()>0)
                ret.push_back(v);
        }
        return ret;
    }
    
    int height(TreeNode *root, unordered_map<TreeNode*, int> &m, vector<vector<int>> &ans) {
        if(root == NULL)
            return 0;
        int leftheight = height(root->left, m, ans);
        int rightheight = height(root->right, m, ans);
        int height = 1 + max(leftheight, rightheight);
        m[root] = height;
        ans[height].push_back(root->val);
        return height;
    }
};