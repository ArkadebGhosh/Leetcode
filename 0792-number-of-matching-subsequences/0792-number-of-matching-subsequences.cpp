class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char, set<int>> m;
        for(int i = 0; i<s.size(); i++) {
            m[s[i]].insert(i);
        }
        
        int ans = 0;
        for(auto &word: words) {
            cout<<word<<endl;
            int pos = 0;
            bool ok = true;
            for(int i = 0; i<word.size(); i++) {
                set<int>:: iterator it = m[word[i]].lower_bound(pos);
                if(it == m[word[i]].end()) {
                    ok = false;
                    break;
                }
                pos = *it+1;
            }
            if(ok)
                ++ans;
        }
        return ans;
    }
};