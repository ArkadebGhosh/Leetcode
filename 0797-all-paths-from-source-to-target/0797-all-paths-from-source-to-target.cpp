class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> currpath;
        vector<vector<int>> ans;
        int n = graph.size();
        dfs(0, graph, currpath, ans, n);
        return ans;
    }
    
    void dfs(int v, vector<vector<int>>& graph, vector<int> &currpath, vector<vector<int>> &ans, int n) {
        currpath.push_back(v);
        if(v==n-1)
            ans.push_back(currpath);
        for(auto &neigh: graph[v]) {
            dfs(neigh, graph, currpath, ans, n);
        }
         currpath.pop_back();
    }
};