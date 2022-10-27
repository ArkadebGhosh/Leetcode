#define lli long long int
class Solution {
public:
    int dp[20001];
    int racecar(int target) {
        if(dp[target]>0)
            return dp[target];
        int t = target + 1;
        int n = (int)log2(t);
        if((t & t-1) == 0) {
            dp[target] = n;
            return n;
        }
        int choice1 = n + 2 + racecar(pow(2, n+1) - 1 - target);
        int choice2 = INT_MAX;
        for(int m = 0; m<n; m++) {
            choice2 = min(choice2, n + 2 + m + racecar( target - pow(2, n) + pow(2, m) ));
        }
        dp[target] = min(choice1, choice2);
        return dp[target];
    }
};