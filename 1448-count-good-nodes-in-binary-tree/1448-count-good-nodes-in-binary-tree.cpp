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
    int goodNodes(TreeNode* root) {
        int goodNodes = 0;
        int currmax = INT_MIN;
        traverse(root, goodNodes, currmax);
        return goodNodes;
    }
    
    void traverse(TreeNode* root, int &goodNodes, int currmax) {
        if(root == NULL)
            return;
        if(root->val >= currmax) {
            currmax = root->val;
            ++goodNodes;
        }
        traverse(root->left, goodNodes, currmax);
        traverse(root->right, goodNodes, currmax);
    }
};