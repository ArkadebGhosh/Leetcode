class Solution {
public:
    bool isValid (vector<int> &freq, int winsize, int k) {
        for(int i = 0; i<26; i++) {
            if(freq[i] >= winsize - k)
                return true;
        }
        return false;
    }
    
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int n = s.size();
        int start = 0, ans = 0;
        for(int i = 0; i<n; i++) {
            freq[s[i] - 'A']++;
            int winsize = i-start+1;
            while(!isValid(freq, winsize, k)) {
                freq[s[start] - 'A']--;
                start++;
                winsize = i - start + 1;
            }
            ans = max(ans, winsize);
        }
        return ans;
    }
};