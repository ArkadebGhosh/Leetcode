class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s;
        int sum = 0, start = 0;
        int ans = 0;
        for(int i = 0; i<n; i++) {
            sum+=nums[i];
            while(s.count(nums[i]) > 0) {
                sum-=nums[start];
                s.erase(nums[start]);
                ++start;
            }
            s.insert(nums[i]);
            ans = max(ans, sum);
        }
        return ans;
    }
};