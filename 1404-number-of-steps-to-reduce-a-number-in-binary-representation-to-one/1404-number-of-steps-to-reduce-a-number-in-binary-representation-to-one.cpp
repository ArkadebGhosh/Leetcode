class Solution {
public:
    int numSteps(string s) {
        int carry = 0;
        int i = 0;
        int n = s.size();
        reverse(s.begin(), s.end());
        int ans = 0;
        // cout<<s<<endl;
        while(i<n) {
            if(s[i] == '0') {
                ++ans;
                ++i;
            }
            else if(i != n-1) {
                carry = 1;
                ans+=1;
                while(i<n && s[i] == '1') {
                    s[i] = '0';
                    ans+=1;
                    ++i;
                }
                // cout<<ans<<endl;
                if(i<n) {
                    s[i] = '1';
                    carry = 0;
                }
                // cout<<s<<endl;
            }
            else
                break;
            // cout<<i<<" "<<ans<<endl;
        }
        return ans;
    }
};