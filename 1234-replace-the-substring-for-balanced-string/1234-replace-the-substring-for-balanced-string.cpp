class Solution {
public:
    int balancedString(string s) {
        int n = s.size();
        int q = 0, w = 0, e = 0, r = 0;
        for(int i = 0; i<n; i++) {
            if(s[i] == 'Q')
                ++q;
            else if(s[i] == 'W')
                ++w;
            else if(s[i] == 'E')
                ++e;
            else
                ++r;
        }
        
        q = max(0, q - n/4);
        w = max(0, w - n/4);
        e = max(0, e - n/4);
        r = max(0, r - n/4);
        // cout<<q<<" "<<w<<" "<<e<<" "<<r<<endl;
        int start = 0;
        int ans = n;
        for(int i = 0; i<n; i++) {
            if(s[i] == 'Q') --q;
            else if(s[i] == 'W') --w;
            else if(s[i] == 'E') --e;
            else --r;
            
            while(start<n && q <= 0 && w<=0 && e<=0 && r<=0) {
                // cout<<i<<" "<<start<<endl;
                ans = min(ans, i - start + 1);
                if(s[start] == 'Q') ++q;
                else if(s[start] == 'W') ++w;
                else if(s[start] == 'E') ++e;
                else ++r;
                ++start;
            }
        }
        return ans;
    }
};