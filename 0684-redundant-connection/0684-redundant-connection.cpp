class Solution {
public:
    int find_parent(int x, vector<int> &parent) {
        while(parent[x]!=x) {
            x = parent[x];
        }
        return x;
    }
    
    void union2(int x , int y, vector<int> &parent) {
        int small = x;
        int large = y;
        if(x>y)
            swap(small, large);
        int py = find_parent(large, parent);
        parent[py] = find_parent(small, parent);
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1, 0);
        for(int i = 1; i<=n; i++)
            parent[i] = i;
        for(auto &edge: edges) {
            int from = edge[0];
            int to = edge[1];
            if(find_parent(from, parent) == find_parent(to, parent)) {
                return {from, to};
            }
            else {
                union2(from, to, parent);
            }
        }
        return {0, 0};
    }
    
    
};