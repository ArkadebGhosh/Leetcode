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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        vector<char> dir1, dir2;
        vector<int> path1, path2;
        bool found1 = false, found2 = false;
        path(root, startValue, dir1, path1, found1);
        path(root, destValue, dir2, path2, found2);
        unordered_set<int> s;
        for(auto &it: path1)
            s.insert(it);
        int common = 0;
        for(int i = path2.size() -1; i>=0; i--) {
            int it = path2[i];
            if(s.count(it)) {
                common = it;
                break;
            }
        }
        string ans = "";
        for(int i = path2.size()-1; i>=0; i--) {
            if(path2[i] !=common) {
                ans+=dir2[i-1];
            }
            else
                break;
        }
        int ups = 0;
        for(int i = 0; i<path2.size(); i++) {
            if(path1[i] == common) {
                ups = path1.size() - i - 1;
                break;
            }
        }
        reverse(ans.begin(), ans.end());
        string up = "";
        for(int i = 1; i<=ups; i++)
            up+='U';
        ans = up + ans;
        return ans;
    }
    
    void path(TreeNode *root, int dest, vector<char> &directions, vector<int> &arr, bool &found) {
        if(found == true)
            return;
        arr.push_back(root->val);
        if(root->val == dest) {
            found = true;
            return;
        }
        if(root->left) {
            if(found == true)
                return;
            directions.push_back('L');
            path(root->left, dest, directions, arr, found);
            if(found == false)
                directions.pop_back();
        }
        if(root->right) {
            if(found == true)
                return;
            directions.push_back('R');
            path(root->right, dest, directions, arr, found);
            if(found == false)
                directions.pop_back();
        }
        if(found == true)
            return;
        arr.pop_back();
    }
};