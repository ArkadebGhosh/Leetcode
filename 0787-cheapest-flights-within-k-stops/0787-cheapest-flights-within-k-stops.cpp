class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        for(int i = 1; i<=k+1; i++) {
            vector<int> temp = dist;
            for(auto &edge: flights) {
                if(dist[edge[0]]!= INT_MAX && temp[edge[1]] > dist[edge[0]] + edge[2]) {
                    temp[edge[1]] = dist[edge[0]] + edge[2];
                }
            }
            dist = temp;
        }
        if(dist[dst] == INT_MAX)
            return -1;
        return dist[dst];
    }
};