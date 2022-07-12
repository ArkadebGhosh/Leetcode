class Solution {
public:
    int maxProfit(int K, vector<int>& prices) {
        int n = prices.size();
        if(n==0)
            return 0;
        if(K==0)
            return 0;
        int ones[n][n];
        int dp[K+1][n];
        for(int i = n-1; i>=0; i--) {
            int maxprofit = INT_MIN;
            int maxnow = INT_MIN;
            for(int j = i; j>=0; j--) {
                maxnow = max(maxnow, prices[j]);
                // cout<<maxnow<<" "<<prices[j]<<" ";
                ones[j][i] = maxprofit = max(maxprofit, maxnow - prices[j]);
                if(j==0)
                    dp[1][i] = ones[j][i];
                // cout<<maxprofit<<endl;
            }
        }
        
        for(int k = 2; k<=K; k++) {
            for(int i = 0; i<n; i++) {
                dp[k][i] = 0;
                for(int j = 0; j<i-1; j++) {
                    dp[k][i] = max(dp[k][i], dp[k-1][j] + ones[j+1][i]);
                }
                dp[k][i] = max(dp[k][i], dp[k-1][i]);
            }
        }
        // for(int k = 1; k<=K; k++) {
        //     for(int i = 0; i<n; i++) {
        //         cout<<"k="<<k<<", i="<<i<<" : "<<dp[k][0][i]<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[K][n-1];
    }
};