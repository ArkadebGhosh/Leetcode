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

struct ele{
    TreeNode* node;
    int lvl;
    int depth;
};

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        int low = 0, high = 0;
        unordered_map<int, multiset<pair<int, int>>> m;
        queue<ele> q;
        q.push({root, 0, 0});
        while(!q.empty()) {
            TreeNode* curr = q.front().node;
            int lvl = q.front().lvl;
            int depth = q.front().depth;
            low = min(low, lvl);
            high = max(high, lvl);
            m[lvl].insert({depth, curr->val});
            if(curr->left)
                q.push({curr->left, lvl-1, depth+1});
            if(curr->right)
                q.push({curr->right, lvl+1, depth+1});
            q.pop();
        }
        vector<vector<int>> ans;
        for(int i = low; i<=high; i++) {
            vector<int> temp;
            for(auto &it: m[i]) {
                temp.push_back(it.second);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};