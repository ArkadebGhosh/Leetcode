class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> m;
        int n = cpdomains.size();
        for(int i = 0; i<n; i++) {
            string s = cpdomains[i];
            int k = 0;
            string cdom = "";
            while(s[k] != ' ') {
                cdom+=s[k];
                k++;
            }
            int count = stoi(cdom);
            // cout<<count<<endl;
            string temp = "";
            for(int j = s.size()-1; j >= 0; j--) {
                if(s[j]!='.' && s[j] != ' ') {
                    temp+=s[j];
                }
                
                else {
                    string temp2 = temp;
                    reverse(temp2.begin(), temp2.end());
                    // cout<<temp2<<endl;
                    m[temp2] += count;
                    temp += '.';
                    if(s[j] == ' ')
                        break;
                }
            }
        }
        vector<string> ans;
        for(auto &it: m) {
            ans.push_back(to_string(it.second)+" "+it.first);
        }
        return ans;
    }
};