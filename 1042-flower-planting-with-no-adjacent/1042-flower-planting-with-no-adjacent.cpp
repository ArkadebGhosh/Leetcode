class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> g(n+1, vector<int> (0, 0));
        for(auto &it: paths) {
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }
        vector<int> visited(n, 0);
        vector<int> c = {1,2,3,4};
        for(int i = 1; i<=n; i++) {
            if(visited[i-1]) 
                continue;
            unordered_set<int>choices(c.begin(), c.end());
            for(auto &neigh: g[i])
                choices.erase(visited[neigh-1]);
            visited[i-1] = *(choices.begin());
        }
        
        return visited;
        
    }
};