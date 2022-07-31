#define lli long long int
class Solution {
    lli distance(vector<int> p1) {
        lli dx = p1[0];
        lli dy = p1[1];
        return dx*dx + dy*dy;
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<lli, pair<int,int>>> pq;
        for(auto &point: points) {
            if(pq.size() < k)
                pq.push({distance(point), {point[0], point[1]}});
            else {
                lli dis = distance(point);
                if(dis < pq.top().first) {
                    pq.push({dis, {point[0], point[1]}});
                    pq.pop();
                }
            }
        }
        
        vector<vector<int>> ans;
        while(!pq.empty()) {
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            ans.push_back({x, y});
            pq.pop();
        }
        return ans;
    }
};