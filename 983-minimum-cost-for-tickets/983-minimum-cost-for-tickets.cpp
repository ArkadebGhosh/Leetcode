class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n+1, INT_MAX);
        dp[n-1] = min(costs[0], min(costs[1], costs[2]));
        dp[n] = 0;
        for(int i = n-2; i>=0; i--) {
            dp[i] = costs[0] + dp[i+1];
            for(int j = i+1; j<min(n, i+30); j++) {
                if(days[j] - days[i] < 7)
                    dp[i] = min(dp[i], costs[1] + dp[j+1]);
                if(days[j] - days[i] < 30)
                    dp[i] = min(dp[i], costs[2] + dp[j+1]);
                if(days[j] - days[i] >= 30)
                    break;
            }
        }
        return dp[0];
    }
};