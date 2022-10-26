class Solution {
public:
    static bool cmp(string w1, string w2) {
        return w1.size() < w2.size();
    }
    
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> chain;
        for(auto &word: words)
            chain[word] = 1;
        sort(words.begin(), words.end(), cmp);
        int ans = 1;
        for(int i = 0; i<words.size(); i++) {
            for(int j = i-1; j>=0; j--) {
                if(words[j].size() == words[i].size()-1 && related(words[j], words[i])) {
                    chain[words[i]] = max(chain[words[i]], chain[words[j]] + 1);
                    ans = max(ans, chain[words[i]]);
                }
            }
        }
        return ans;
    }
    
    bool related(string s1, string s2) {
        if(s1.size() != s2.size()-1)
            return false;
        int i = 0;
        int j = 0;
        bool f = false;
        while(i<s1.size() && j<s2.size()) {
            if(s1[i] == s2[j]) {
                ++i;
                ++j;
            }
            else if(s1[i] != s2[j] && f==0) {
                f = 1;
                j++;
            }
            else if(s1[i]!=s2[j]) {
                return false;
            }
        }
        return true;        
    }
};