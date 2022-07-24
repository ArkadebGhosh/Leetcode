class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<string> strings;
        for(auto &it: arr) {
            if(safe(it, ""))
                strings.push_back(it);
        }
        return comb("", strings, 0, strings.size()-1);
    }
    
    int comb(string start, vector<string> &arr, int begin, int end) {
        int ans = start.size();
        if(begin>end)
            return ans;
        for(int i = begin; i<=end; i++) {
            if(safe(start, arr[i])) {
                string appended = start + arr[i];
                // cout<<start<<" "<<arr[i]<<" "<<appended<<endl;
                ans = max(ans, comb(appended, arr, i+1, end));
                // cout<<"ans for "<<start<<" "<<arr[i]<<" "<<appended<<":- "<<ans<<endl;
            }
        }
        // cout<<start<<" "<<ans<<endl;
        return ans;
    }
    
    bool safe(string s1, string s2) {
        unordered_set<char> s;
        for(auto &ch: s1) {
            if(s.count(ch) > 0)
                return false;
            s.insert(ch);
        }
        
        for(auto &ch: s2) {
            if(s.count(ch) > 0)
                return false;
        }
        return true;
    }
};