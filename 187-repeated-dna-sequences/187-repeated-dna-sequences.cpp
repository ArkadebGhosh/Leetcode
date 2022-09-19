class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        if(n<=9)
            return {};
        int i = 0, j = 9;
        unordered_map<string, int> m;
        for(int i = 0; i<n-9; i++) {
            string str = s.substr(i, 10);
            m[str]+=1;
        }
        vector<string> ans;
        for(auto &it: m) {
            if(it.second>1)
                ans.push_back(it.first);
        }
        return ans;
    }
};