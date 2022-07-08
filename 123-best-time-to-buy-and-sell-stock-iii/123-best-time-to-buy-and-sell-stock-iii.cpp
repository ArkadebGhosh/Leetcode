class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        int minleft = INT_MAX;
        int maxright = INT_MIN;
        for(int i = 1; i < n; i++) {
            minleft = min(minleft, prices[i-1]);
            left[i] = max(left[i-1], prices[i] - minleft);
            maxright = max(maxright, prices[n-i]);
            right[n-1-i] = max(right[n-1-i], maxright - prices[n-i-1]);
        }
        int ans = 0;
        for(int i = 0; i<n; i++) {
            ans = max(ans, left[i] + right[i]);
        }
        return ans;
    }
};