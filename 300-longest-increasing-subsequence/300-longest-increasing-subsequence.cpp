class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // DP Solution: 
        // int n = nums.size();
        // int ans = 1;
        // int dp[n];
        // dp[0] = 1;
        // for(int i = 1; i<n; i++) {
        //     dp[i] = 1;
        //     for(int j = i-1; j>=0; j--) {
        //         if(nums[j] < nums[i])
        //             dp[i] = max(dp[i], dp[j] + 1);
        //     }
        //     ans = max(ans, dp[i]);
        // }
        // return ans;
        
        // NlogN Solution:
        vector<int> tails;
        tails.push_back(nums[0]);
        for(int i  = 1; i<nums.size(); i++) {
            if(nums[i] > tails.back())
                tails.push_back(nums[i]);
            else {
                int j = lower_bound(tails.begin(), tails.end(), nums[i]) - tails.begin();
                tails[j] = nums[i];
            }
        }
        return tails.size();
    }
};