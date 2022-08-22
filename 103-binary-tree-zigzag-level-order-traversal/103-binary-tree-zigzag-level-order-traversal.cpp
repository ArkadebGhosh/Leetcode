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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL)
            return {};
        int currlvl = 0;
        vector<vector<int>> ans;
        ans.push_back({});
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()) {
            TreeNode *curr = q.front().first;
            int lvl = q.front().second;
            if(lvl == currlvl) {
                ans.back().push_back(curr->val);
            }
            else {
                if(currlvl%2 == 1) {
                    reverse(ans.back().begin(), ans.back().end());
                }
                ans.push_back({curr->val});
                currlvl = lvl;
            }
            if(curr->left)
                q.push({curr->left, lvl+1});
            if(curr->right)
                q.push({curr->right, lvl+1});
            q.pop();
        }
        if(currlvl%2 == 1)
            reverse(ans.back().begin(), ans.back().end());
        return ans;
    }
};