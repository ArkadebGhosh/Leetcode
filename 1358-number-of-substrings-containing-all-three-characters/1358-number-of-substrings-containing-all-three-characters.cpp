class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        int a = -1, b = -1, c = -1;
        for(int i = 0; i<n; i++) {
            if(s[i] == 'a')
                a = i;
            else if(s[i] == 'b')
                b = i;
            else
                c = i;
            int minLastTwo;
            if(s[i] == 'a')
                minLastTwo = min(b, c);
            else if(s[i] == 'b')
                minLastTwo = min(a, c);
            else
                minLastTwo = min(a, b);
            ans += (i + 1) - (i - minLastTwo);
        }
        return ans;
    }
};