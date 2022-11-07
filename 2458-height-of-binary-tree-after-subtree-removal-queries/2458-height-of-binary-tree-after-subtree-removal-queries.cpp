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
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        unordered_map<int, int> ht;
        unordered_map<int, priority_queue<pair<int, int>>> dp;
        unordered_map<int, int> dpth;
        height(root, 0, ht, dp, dpth);
        vector<int> ret;
        for(auto &query: queries) {
            int ans = ht[root->val] - ht[query];
            int depth = dpth[query];
            int greatest_at_depth = dp[depth].top().second;
            if(greatest_at_depth != query) {
                ans = ht[root->val];
            }
            else {
                pair<int, int> temp = dp[depth].top();
                dp[depth].pop();
                if(dp[depth].size() != 0) 
                    ans = ans + dp[depth].top().first;
                dp[depth].push(temp);
            }
            ret.push_back(ans-1);
        }
        return ret;
    }
    
    int height(TreeNode* root, int depth, unordered_map<int, int> &ht, unordered_map<int, priority_queue<pair<int, int>>> &dp, unordered_map<int, int> &dpth) {
        if(root == NULL) 
            return 0;
        int lh = 0, rh = 0;
        dpth[root->val] = depth;
        lh = height(root->left, depth+1, ht, dp, dpth);
        rh = height(root->right, depth+1, ht, dp, dpth);
        ht[root->val] = 1 + max(lh, rh);
        dp[depth].push({ht[root->val], root->val});
        return ht[root->val];
    }
};