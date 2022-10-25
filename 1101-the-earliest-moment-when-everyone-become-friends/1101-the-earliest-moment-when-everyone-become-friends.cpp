class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        map<int, vector<pair<int, int>>> activity;
        for(auto &log: logs) {
            activity[log[0]].push_back({log[1], log[2]});
        }
        
        //DSU
        vector<int> parent(n);
        for(int i = 0; i<n; i++)
            parent[i] = i;
        vector<int> rank(n, 1);
        vector<int> size(n, 1);
        
        for(auto &stage: activity) {
            for(auto &edge: stage.second) {
                int from = edge.first;
                int to = edge.second;
                int s1 = size[find_parent(from, parent)];
                int s2 = size[find_parent(to, parent)];
                bool diff = merge(from, to, parent, rank, size);
                if(diff == false)
                    continue;
                if(s1 + s2 == n)
                    return stage.first;
            }
        }
        return -1;
    }
    
    int find_parent(int x, vector<int> &parent) {
        while(parent[x] != x) {
            x = parent[x];
        }
        return x;
    }
    
    bool merge(int x, int y, vector<int> &parent, vector<int> &rank, vector<int> &size) {
        int px = find_parent(x, parent);
        int py = find_parent(y, parent);
        if(px == py)
            return false;
        else {
            if(rank[px] > rank[py]) {
                parent[py] = px;
                size[px] += size[py];
            }
            else if(rank[py] < rank[px]) {
                parent[px] = py;
                size[py] += size[px];
            }
            else {
                parent[py] = px;
                rank[px]+=1;
                size[px] += size[py];
            }
        }
        return true;
    }
};