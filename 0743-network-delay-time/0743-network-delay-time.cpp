class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int, int>>> g(n+1);
        for(auto time: times) {
            int from = time[0];
            int to = time[1];
            int wt = time[2];
            g[from].push_back({to, wt});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // unordered_set<int> completed;
        vector<int> dis(n+1, 5000000);
        pq.push({0, k});
        // visited[k] = 1;
        dis[k] = 0;
        while(!pq.empty()) {
            int currv = pq.top().second;
            int currwt = pq.top().first;
            // completed.push_back(currv);
            pq.pop();
            for(auto neigh: g[currv]) {
                int nv = neigh.first;
                int nwt = neigh.second;
                // if(completed.find(nv) != completed.end())
                //     continue;
                if(dis[nv] > currwt + nwt) {
                    dis[nv] = currwt + nwt;
                    pq.push({dis[nv], nv});
                }
            }
        }
        // if(completed.size() < n)
        //     return -1;
        int high = INT_MIN;
        for(int i = 1; i<=n; i++) {
            if(dis[i] == 5000000)
                return -1;
            else if(dis[i] > high)
                high = dis[i];
        }
        return high;
    }
};