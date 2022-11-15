class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp (n , vector<int> (1001, 1));
        int ans = 1;
        for(int i = 0; i<nums.size(); i++) {
            for(int j = i-1; j>=0; j--) {
                int diff = nums[i] - nums[j];
                diff+=500;
                dp[i][diff] = max(dp[i][diff], dp[j][diff] + 1);
                ans = max(ans, dp[i][diff]);
            }
        }
        return ans;
    }
};