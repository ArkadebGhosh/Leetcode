class Solution {
public:
    bool checkPartitioning(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool> (n, false));
        for(int i = 0; i<n; i++) {
            expand(s, i, i, n, dp);
            expand(s, i, i+1, n, dp);
        }
        
        for(int i = 0; i<n-2; i++) {
            for(int j = i+1; j<n-1; j++) {
                if(dp[0][i] && dp[i+1][j] && dp[j+1][n-1]) {
                    // cout<<i<<" "<<j<<endl;
                    return true;
                }
            }
        }
        return false;
    }
    
    void expand(string &s, int c1, int c2, int n, vector<vector<bool>> &dp) {
        while(c1>=0 && c2<n && s[c1] == s[c2]) {
            dp[c1][c2] = true;
            c1--;
            c2++;
        }
    }
};