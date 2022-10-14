class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
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
    }
};