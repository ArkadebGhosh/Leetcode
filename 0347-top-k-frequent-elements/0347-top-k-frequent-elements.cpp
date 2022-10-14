class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        /*
        O(N + KlogN)
        unordered_map<int, int> m;
        for(auto &it: nums)
            m[it]++;
        vector<pair<int, int>> v;
        for(auto &it: m)
            v.push_back({it.second, it.first});
        priority_queue<pair<int, int>> pq(v.begin(), v.end());
        vector<int> ans;
        while(k--) {
            int top = pq.top().second;
            pq.pop();
            ans.push_back(top);
        }
        return ans;
        */
        
        // O (N + NlogK)
        unordered_map<int, int> m;
        for(auto &it: nums)
            m[it]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(auto &it: m) {
            int ele = it.first;
            int freq = it.second;
            if(pq.size() < k) {
                pq.push({freq, ele});
            }
            else {
                if(pq.top().first < freq) {
                    pq.pop();
                    pq.push({freq, ele});
                }
            }
        }
        vector<int> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};