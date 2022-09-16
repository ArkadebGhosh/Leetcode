class Solution {
    
public:
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size();
        int m = multipliers.size();
        vector<vector<int>> memo (m, vector<int>(m, INT_MIN));
        return solve(nums, multipliers, 0, 0, memo);
    }
    
    int solve(vector<int>& nums, vector<int>& multipliers, int start, int idx, vector<vector<int>> &memo) {
        if(idx >= memo.size())
            return 0;
        if(memo[start][idx]!=INT_MIN) {
            return memo[start][idx];
        }
        int end = (nums.size()-1) - (idx - start);
        int ans = max(nums[start] * multipliers[idx] + solve(nums, multipliers, start+1, idx+1, memo),
                     nums[end] * multipliers[idx] + solve(nums,multipliers, start, idx+1, memo));
        memo[start][idx] = ans;
        return ans;
    }
};