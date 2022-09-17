class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();
        unordered_map<string, int> m;
        for(int i = 0; i<n; i++) {
            m[words[i]] = i;
        }
        vector<vector<int>> ans;
        for(int i = 0; i<n; i++) {
            string word = words[i];
            int len = word.size();
            if(len == 0)
                continue;
            // cout<<"*************"<<endl;
            int start = (len-1)/2;
            for(int j = 0; j<len; j++) {
                string req1 = required(word, j, j, m);
                string req2 = required(word, j, j+1, m);
                // cout<<req1<<" "<<req2<<endl;
                if(m.count(req1) && m[req1]!=i) {
                    if(req1.size()==0) {
                        ans.push_back({i, m[req1]});
                        ans.push_back({m[req1], i});
                    }
                    else if(j > (len-1)/2)
                        ans.push_back({i, m[req1]});
                    else
                        ans.push_back({m[req1], i});
                }
                if(m.count(req2) && m[req2]!=i) {
                    if(req2.size() == 0) {
                        ans.push_back({i, m[req2]});
                        ans.push_back({m[req2], i});
                    }
                    else if(j >= (len-1)/2)
                        ans.push_back({i, m[req2]});
                    else
                        ans.push_back({m[req2], i});
                }
            }
        }
        return ans;
    }
    
    string required(string &s, int c1, int c2, unordered_map<string, int> &m) {
        while(c1>=0 && c2<s.size() && s[c1] == s[c2]) {
            c1--;
            c2++;
        }
        
        string req = "";
        if(c1 == -1 && c2==s.size()) {
            return req;
        }
        
        if(c1>=0 && c2<s.size() && s[c1]!=s[c2]) {
            return "$";
        }
        
        if(c1 >= 0) {
            string ans = s.substr(0, c1+1);
            reverse(ans.begin(), ans.end());
            return ans;
        }
        
        if(c2 < s.size()) {
            string ans = s.substr(c2);
            reverse(ans.begin(), ans.end());
            return ans;
        }
        
        return req;
    } 
};