class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)
            return {0};
        if(n==2)
            return {0, 1};
        unordered_set<int> g[n];
        for(int i = 0; i<n-1; i++) {
            g[edges[i][0]].insert(edges[i][1]);
            g[edges[i][1]].insert(edges[i][0]);
        }
        queue<int> q;
        vector<int> visited(n, 0);
        
        for(int i = 0; i<n; i++) {
            if(g[i].size() <= 1) {
                visited[i] = 1;
                q.push(i);
            }
        }
        
        int nvisited = q.size();
        while(q.size() > 2 || nvisited!=n) {
            unordered_set<int> leafs;
            while(!q.empty()) {
                int front = q.front();
                q.pop();
                for(auto &it: g[front]) {
                    g[it].erase(front);
                    if(g[it].size() <= 1) {
                        if(!visited[it]) {
                            leafs.insert(it);
                            visited[it] = 1;
                            nvisited += 1;
                        }
                    }
                }
            }
            for(auto &it: leafs)
                q.push(it);
        }
        vector<int> ans;
        while(!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};