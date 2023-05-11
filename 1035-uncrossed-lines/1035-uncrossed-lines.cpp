class Solution {
public:
    //Longest Common Subsequence
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return lcs(nums1, nums2, 0, 0, dp);
    }
    
    int lcs(vector<int> &nums1, vector<int> &nums2, int s1, int s2, vector<vector<int>> &dp) {
        if(s1 == nums1.size() || s2 == nums2.size())
            return 0;
        if(dp[s1][s2] != -1)
            return dp[s1][s2];
        if(nums1[s1] == nums2[s2]) 
            dp[s1][s2] = 1 + lcs(nums1, nums2, s1+1, s2+1, dp);
        else 
            dp[s1][s2] = max(lcs(nums1, nums2, s1+1, s2, dp), lcs(nums1, nums2, s1, s2+1, dp));
        return dp[s1][s2];
    }
};