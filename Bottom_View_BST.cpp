class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        unordered_map<int,int> m;
        // map<int,int> m;
        queue<pair<Node*, int>> q;
        int low = 0;
        int high = 0;
        q.push({root, 0});
        while(!q.empty()) {
            Node *curr = q.front().first;
            int level = q.front().second;
            low = min(low, level);
            high = max(high, level);
            m[level] = curr->data;
            if(curr->left)
            q.push({curr->left, level - 1});
            if(curr->right)
            q.push({curr->right, level + 1});
            q.pop();
        }
        vector<int> ans;
        // for(auto &it: m)
        // ans.push_back(it.second);
        for(int i = low; i<=high; i++)
        ans.push_back(m[i]);
        return ans;
    }
};
