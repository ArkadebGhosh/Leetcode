class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        unordered_set<int> whole;
        for(auto &it: coins)
            whole.insert(it);
        vector<int> dp(amount+1, 1e6);
        dp[0] = 0;
        for(int i = 1; i<=amount; i++) {
            if(whole.count(i))
                dp[i] = 1;
            else {
                for(auto &coin: coins) {
                    if(i-coin < 0)
                        continue;
                    dp[i] = min(dp[i], 1 + dp[i-coin]);
                }
            }
        }
        if(dp[amount] >= 1e6)
            return -1;
        return dp[amount];
    }
};