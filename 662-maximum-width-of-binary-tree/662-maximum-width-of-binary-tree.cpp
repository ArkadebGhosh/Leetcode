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
struct ele {
    TreeNode* node;
    unsigned long long int lvl;
    int depth;
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        vector<ele> v;
        v.push_back({root, 0, 0});
        int currdepth = 0;
        unsigned long long int low = 0;
        unsigned long long int high = 0;
        unsigned long long int ans = 1;
        for(int i=0; i<v.size(); i++) {
            TreeNode* curr = v[i].node;
            unsigned long long int lvl = v[i].lvl;
            int depth = v[i].depth;
            if(curr->left)
                v.push_back({curr->left, 2*lvl + 1, depth+1});
            if(curr->right)
                v.push_back({curr->right, 2*lvl + 2, depth+1});
            if(depth!=currdepth) {
                ans = max(ans, high - low + 1);
                low = lvl;
                currdepth = depth;
            }
            high = lvl;
        }
        ans = max(ans, high - low + 1);
        return (int)ans;
    }
};