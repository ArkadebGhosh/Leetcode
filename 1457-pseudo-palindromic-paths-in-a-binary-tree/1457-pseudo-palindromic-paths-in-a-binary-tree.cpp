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
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_set<int> m;
        int num_odd = 0;
        int ans = 0;
        check(root, m, ans);
        return ans;
    }
    
    void check(TreeNode *root, unordered_set<int> &m, int &ans) {
        bool erased = false;
        if(m.count(root->val)) {
            m.erase(root->val);
            erased = true;
        }            
        else
            m.insert(root->val);
        if(root->left == NULL && root->right == NULL) {
            if(m.size() <= 1)
                ++ans;
            // cout<<root->val<<" "<<m.size()<<" "<<ans<<endl;
        }
        if(root->left) {
            check(root->left, m, ans);
        }
        if(root->right) {
            check(root->right, m, ans);
        }
        if(erased)
            m.insert(root->val);
        else
            m.erase(root->val);
    }
};