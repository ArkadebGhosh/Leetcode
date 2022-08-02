class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int c = 0;
        int n = s.size();
        string ans = "";
        for(int i = n-1; i>=0; i--) {
            if(s[i] == '-')
                continue;
            if(c!=0 && c%k == 0)
                ans+='-';
            ans += toupper(s[i]);
            ++c;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};