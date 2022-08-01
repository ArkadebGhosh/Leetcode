class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> st;
        unordered_map<char,int> lastpos;
        for(int i = s.size()-1; i>=0; i--) {
            if(!lastpos.count(s[i]))
                lastpos[s[i]] = i;
        }
        unordered_set<char> included;
        for(int i = 0; i<s.size(); i++) {
            if(included.count(s[i]))
                continue;
            if(st.empty() || st.top() < s[i]) {
                st.push(s[i]);
                included.insert(s[i]);
            }
            else {
                while (!st.empty() && st.top() > s[i] && lastpos[st.top()] > i) {
                    included.erase(st.top());
                    st.pop();
                }
                st.push(s[i]);
                included.insert(s[i]);
            }
        }
        string ans = "";
        while(!st.empty()) {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};