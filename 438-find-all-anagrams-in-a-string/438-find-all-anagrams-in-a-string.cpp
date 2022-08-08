class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int uniquepat = 0;
        vector<int> freq(26, 0);
        int n = s.size();
        for(int i = 0; i<p.size(); i++)
            freq[p[i]-'a']++;
        int start = 0;
        vector<int> ans;
        for(int i = 0; i<n; i++) {
            freq[s[i]-'a']--;
            while(freq[s[i] - 'a'] == -1) {
                freq[s[start]-'a']++;
                start++;
            }
            if(i-start+1 == p.size())
                ans.push_back(start);
        }
        return ans;
    }
};