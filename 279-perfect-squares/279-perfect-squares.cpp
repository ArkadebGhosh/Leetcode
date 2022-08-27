class Solution {
public:
    int numSquares(int n) {
        unordered_set<int> squares;
        int gen = 1;
        while(gen * gen <= 1e4) {
            squares.insert(gen * gen);
            ++gen;
        }
        vector<int> dp(n+1, -1);
        return solve(n, squares, dp);
    }
    
    int solve(int n, unordered_set<int> &squares, vector<int> &dp) {
        if(dp[n] != -1)
            return dp[n];
        if(n==0) {
            dp[n] = 0;
            return 0;
        }
        else if(squares.count(n)) {
            dp[n] = 1;
            return 1;
        }
        dp[n] = n;
        for(auto &it: squares) {
            if(it<=n)
            dp[n] = min(dp[n], 1 + solve(n-it, squares, dp));
        }
        return dp[n];
    }
};