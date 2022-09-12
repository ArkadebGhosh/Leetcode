class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_set<int> graph[n];
        for(auto &it: roads) {
            graph[it[0]].insert(it[1]);
            graph[it[1]].insert(it[0]);
        }
        int ans = INT_MIN;
        for(int i = 0; i<n-1; i++) {
            for(int j = i+1; j<n; j++) {
                int connected = 0;
                if(graph[i].count(j))
                    connected = 1;
                ans = max(ans, (int) (graph[i].size() + graph[j].size() - connected));
            }
        }
        return ans;
    }
};