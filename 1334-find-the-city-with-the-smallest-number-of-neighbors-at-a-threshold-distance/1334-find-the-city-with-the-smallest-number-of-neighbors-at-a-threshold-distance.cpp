class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dis(n, vector<int> (n, INT_MAX));
        for(auto &edge: edges) {
            int from = edge[0];
            int to = edge[1];
            int wt = edge[2];
            dis[from][to] = wt;
            dis[to][from] = wt;
        }
        
        for(int k = 0; k<n; k++) {
            for(int i = 0; i<n; i++) {
                for(int j = 0; j<n; j++) {
                    if(dis[i][k]!=INT_MAX && dis[k][j]!=INT_MAX && dis[i][j] > dis[i][k] + dis[k][j]) {
                        dis[i][j] = dis[i][k] + dis[k][j];
                    }
                }
            }
        }
        
        int city = -1;
        int adj = INT_MAX;
        for(int i = 0; i<n;i++) {
            int count = 0;
            for(int j = 0; j<n; j++) {
                if(i!=j && dis[i][j] <= distanceThreshold)
                    ++count;
            }
            if(count <= adj) {
                city = i;
                adj = count;
            }
        }
        return city;
    }
};