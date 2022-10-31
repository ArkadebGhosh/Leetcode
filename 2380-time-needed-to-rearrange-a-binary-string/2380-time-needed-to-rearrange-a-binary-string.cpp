class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int lz = 0; //zeros to left
        int wt = 0; // wait time
        int prev = -1;
        int ans = 0;
        int n = s.size();
        for(int i = 0; i<n; i++) {
            if(s[i] == '0') {
                wt = max(0, wt - 1);
                ++lz;
            }
            else {
                // cout<<lz<<" "<<wt<<endl;
                if(lz == 0)
                    continue;
                ans = max(ans, lz + wt);
                ++wt;
            }
        }
        return ans;
    }
};