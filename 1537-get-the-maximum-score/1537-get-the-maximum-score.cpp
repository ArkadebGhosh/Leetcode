class Solution {
public:
    int MOD = 1e9+7;
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, vector<int>> g;
        for(int i = 0; i<nums1.size() - 1; i++) {
            g[nums1[i]].push_back(nums1[i+1]);
        }
        for(int i = 0; i<nums2.size() - 1; i++) {
            g[nums2[i]].push_back(nums2[i+1]);
        }
        unordered_map<int, long long int> memo;
        long long int ans1 = path(nums1[0], g, memo);
        long long int ans2 = path(nums2[0], g, memo);
        if(ans1 > ans2)
            return (int)(ans1%MOD);
        return (int)(ans2%MOD);
    }
    
    long long int path(long long int v, unordered_map<int, vector<int>> &g, unordered_map<int, long long int> &memo) {
        if(memo.count(v))
            return memo[v];
        if(g[v].size() == 0) {
            memo[v] = v;
            return v;
        }
        if(g[v].size() == 1) {
            memo[v] = (v + path(g[v][0], g, memo));
            return memo[v];
        }
        if(g[v].size() == 2) {
            memo[v] = (v + max(path(g[v][0], g, memo), path(g[v][1], g, memo)));
            return memo[v];
        }
        return 0;
    }
};