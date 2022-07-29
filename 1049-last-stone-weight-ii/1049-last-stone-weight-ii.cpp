class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for(auto &it: stones)
            sum+=it;
        // cout<<sum<<"dd"<<endl;
        int n = stones.size();
        vector<vector<int>> dp(sum/2+1, vector<int>(n+1, -1));
        int x = closest(0, sum/2, 0, stones, dp);
        return (sum - 2*x); 
    }
    
    int closest(int curr, int rem, int idx, vector<int> &arr, vector<vector<int>> &dp) {
        if(dp[rem][idx] != -1)
            return dp[rem][idx];
        if(idx >= arr.size())
            return curr;
        if(rem<arr[idx]) {
            dp[rem][idx] = closest(curr, rem, idx+1, arr, dp);
            return dp[rem][idx];
        }
        dp[rem][idx] = max(closest(curr+arr[idx], rem - arr[idx], idx+1, arr, dp), closest(curr, rem, idx+1, arr, dp));
        return dp[rem][idx];
    }
};