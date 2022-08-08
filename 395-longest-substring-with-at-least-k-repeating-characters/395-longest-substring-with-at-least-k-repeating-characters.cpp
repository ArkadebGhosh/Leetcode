class Solution {
public:
    int longestSubstring(string s, int k) {
        int totUnique = 0;
        int n = s.size();
        vector<int> freq(26, 0);
        for(int i = 0; i<n; i++) {
            if(freq[s[i] - 'a'] == 0)
                ++totUnique;
            freq[s[i] - 'a']++;
        }
        // cout<<totUnique<<endl;
        int ans = 0;
        for(int unique = 1; unique<=totUnique; unique++) {
            freq = vector<int> (26, 0);
            int currUnique = 0;
            int currSatisfied = 0;
            int start = 0;
            for(int i = 0; i<n; i++) {
                if(freq[s[i] - 'a'] == 0)
                    ++currUnique;
                freq[s[i] - 'a']++;
                if(freq[s[i] - 'a'] == k)
                    ++currSatisfied;
                if(currUnique == currSatisfied)
                    ans = max(ans, i-start+1);
                while(currUnique > unique) {
                    if(freq[s[start] -'a'] == k)
                        --currSatisfied;
                    freq[s[start] - 'a']--;
                    if(freq[s[start] - 'a'] == 0)
                        --currUnique;
                    ++start;
                }
            }
        }
        return ans;
    }
};