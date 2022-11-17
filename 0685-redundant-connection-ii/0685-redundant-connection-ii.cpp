class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1);
        for(int i = 1; i<=n; i++)
            parent[i] = i;
        vector<int> incident(n+1, -1); //stores if in degree = 1 is due to edges[val]
        bool indeg2 = false;
        int choice1 = -1, choice2 = -1;
        for(int i = 0; i<edges.size(); i++) {
            int from = edges[i][0];
            int to = edges[i][1];
            if(incident[to] == -1)
            incident[to] = i;
            else {
                indeg2 = true;
                choice1 = i;
                choice2 = incident[to];
                break;
            }
        }
        
        if(indeg2 == false) { // check for cycle to root
            for(auto &edge: edges) {
                int from = edge[0];
                int to = edge[1];
                if(find_parent(from, parent) == find_parent(to, parent))
                    return{from, to};
                union2(from, to, parent);
            }
        }
        
        for(int i = 0; i<edges.size(); i++) {
            if(i == choice1)
                continue;
            int from = edges[i][0];
            int to = edges[i][1];
            if(find_parent(from, parent) == find_parent(to, parent))
                return edges[choice2];
            union2(from, to, parent);
        }
        return edges[choice1];
    }
    
    int find_parent(int x, vector<int> &parent) {
        while(x!=parent[x]) {
            x = parent[x];
        }
        return x;
    }
    
    void union2(int x, int y, vector<int> &parent) {
        int py = parent[y];
        parent[py] = find_parent(x, parent);
    }
};