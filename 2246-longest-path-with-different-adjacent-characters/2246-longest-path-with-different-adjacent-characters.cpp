class Solution {
public:
    int longestPath(vector<int>& parent, string s) {
        int ans = 0;
        int n = parent.size();
        vector<vector<int>> g(n, vector<int> (0, 0));
        for(int i = 1; i<n; i++) {
            int from = parent[i];
            int to = i;
            g[from].push_back(to);
        }
        solve(0, g, s, ans);
        return ans;
    }
    
    int solve(int root, vector<vector<int>> &g, string &s, int &ans) {
        int pathViaRoot = 0;
        char curr = s[root];
        priority_queue<int, vector<int>, greater<int>> pq;
        int longestChain = 1;
        for(auto &neigh: g[root]) {
            char nchar = s[neigh];
            int chainNeigh = solve(neigh, g, s, ans);
            ans = max(ans, chainNeigh);
            if(nchar != curr) {
                longestChain = max(longestChain, 1 + chainNeigh);
                pq.push(chainNeigh);
                if(pq.size()>2) {
                    pq.pop();
                }
            }
        }
        int first = 0;
        int second = 0;
        if(!pq.empty()) {
            first = pq.top();
            pq.pop();
        }
        
        if(!pq.empty()) {
            second = pq.top();
            pq.pop();
        }
        
        ans = max(ans, first + second + 1);
        return longestChain;
    }
};