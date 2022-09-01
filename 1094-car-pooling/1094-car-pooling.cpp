class Solution {
public:
    static bool cmp(vector<int> v1, vector<int> v2) {
        return v1[1] < v2[1];
    }
    
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();
        sort(trips.begin(), trips.end(), cmp);
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int pass = 0;
        for(int i = 0; i<n; i++) {
            while(!pq.empty() && pq.top().first <= trips[i][1]) {
                pass-=pq.top().second;
                pq.pop();
            }
            pass+=trips[i][0];
            if(pass > capacity)
                return false;
            pq.push({trips[i][2], trips[i][0]});
        }
        return true;
    }
};