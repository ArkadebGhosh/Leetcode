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
        vector<vector<int>> ans(100);
        height(root, ans);
        vector<vector<int>> ret;
        for(auto &v: ans) {
            if(v.size()>0)
                ret.push_back(v);
        }
        return ret;
    }
    
    int height(TreeNode *root, vector<vector<int>> &ans) {
        if(root == NULL)
            return 0;
        int leftheight = height(root->left, ans);
        int rightheight = height(root->right, ans);
        int height = 1 + max(leftheight, rightheight);
        ans[height].push_back(root->val);
        return height;
    }
};