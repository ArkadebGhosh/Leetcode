class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [10000000] * (amount+1)
        dp[0] = 0
        entire = {}
        for coin in coins:
            entire[coin] = 1;
        for i in range(1, amount+1):
            if i in entire:
                dp[i] = 1;
            else:
                for coin in coins:
                    if coin > i:
                        continue;
                    dp[i] = min(dp[i], 1+dp[i-coin])
        if dp[amount] >= 10000000:
            return -1;
        return dp[amount];
                        