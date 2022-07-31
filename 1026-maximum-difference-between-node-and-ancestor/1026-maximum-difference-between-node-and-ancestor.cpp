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
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        maxDiff(root, ans);
        return ans;
    }
    
    pair<int,int> maxDiff(TreeNode* root, int &ans) {
        if(root->left == NULL && root->right == NULL) {
            return {root->val, root->val};
        }
        
        int maxhigh, minlow;
        pair<int, int> p1, p2;
        if(root->left != NULL)
            p1 = maxDiff(root->left, ans);
        if(root->right != NULL)
            p2 = maxDiff(root->right, ans);
        
        if(root->left!= NULL && root->right!= NULL) {
            int maxhigh = max(p1.first, p2.first);
            int minlow = min(p1.second, p2.second);
            int choice1 = abs(root->val - maxhigh);
            int choice2 = abs(root->val - minlow);
            int choice = max(choice1, choice2);
            ans = max(ans, choice);
            return {max(maxhigh, root->val), min(minlow, root->val)};
        }
        
        else if(root->left == NULL) {
            int choice1 = abs(root->val - p2.first);
            int choice2 = abs(root->val - p2.second);
            ans = max(ans, max(choice1, choice2));
            return {max(p2.first, root->val), min(p2.second, root->val)};
        }
        
        else if(root->right == NULL) {
            int choice1 = abs(root->val - p1.first);
            int choice2 = abs(root->val - p1.second);
            ans = max(ans, max(choice1, choice2));
            return {max(p1.first, root->val), min(p1.second, root->val)};
        }
        
        return {-1, -1};
        
    }
};