class Solution {
public:
    string rankTeams(vector<string>& votes) {
        
        string ans = votes[0];
        vector<vector<int>> freq(26, vector<int>(26, 0));
        for(auto &vote: votes) {
            for(int i = 0; i<vote.size(); i++) {
                char ch = vote[i];
                freq[ch - 'A'][i]++;
            }
        }
        auto comp = [&](char a, char b)-> bool {
            // cout<<a<<" "<<b<<endl;
            for(int i = 0; i<26; i++) {
                if(freq[a - 'A'][i] > freq[b - 'A'][i])
                    return true;
                else if(freq[a - 'A'][i] < freq[b - 'A'][i])
                    return false;
            }
            return a < b;
        };
        
        sort(ans.begin(), ans.end(), comp);
        return ans;
    }
};