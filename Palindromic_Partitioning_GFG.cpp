int part(string &str, int start, int end, vector<vector<int>> &dp, vector<vector<int>> &isPal) {
        if(start > end)
        return 0;
        if(isPal[start][end] == 1)
        return 0;
        else if(dp[start][end] != -1)
        return dp[start][end];
        int temp = str.size();
        for(int i = start; i<end; i++) {
            temp = min(temp, 1+part(str, start, i, dp, isPal) + part(str, i+1, end, dp, isPal));
        }
        dp[start][end] = temp;
        return temp;
    }
    
    void expand(string &str, int i, int j, vector<vector<int>> &isPal) {
        int n = str.size();
        while(i>=0 && j<n) {
            if(str.at(i) != str.at(j)) {
                isPal[i][j] = 0;
                return;
            }
            isPal[i][j] = 1;
            --i;
            ++j;
        }
    }
    
    int palindromicPartition(string str)
    {
        // code here
        int l = str.size();
        vector<vector<int>> isPal(l, vector<int> (l, 0));
        for(int i = 0; i<l; i++) {
            expand(str, i, i, isPal);
            expand(str, i, i+1, isPal);
        }
        vector<vector<int>> dp(l, vector<int>(l, -1));
        int ans = part(str, 0, l-1, dp, isPal);
        return ans;
    }
