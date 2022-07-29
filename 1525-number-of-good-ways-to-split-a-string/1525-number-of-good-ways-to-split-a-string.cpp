class Solution {
public:
    int numSplits(string s) {
        int l = s.size();
        vector<vector<int>> freq(l, vector<int> (26, 0));
        for(int i = 0; i<l; i++) {
            if(i==0)
                freq[i][s[i] - 'a'] = 1;
            else {
                freq[i] = freq[i-1];
                freq[i][s[i] - 'a'] = freq[i-1][s[i] - 'a'] + 1;
            }
                
        }
        
        // for(int i = 0; i<l; i++) {
        //     for(int j = 0; j<26; j++)
        //         cout<<freq[i][j]<<" ";
        //     cout<<endl;
        // }
        int splits = 0;
        for(int i = 1; i<l; i++) {
            vector<int> zeros(26, 0);
            // cout<<unique(freq[l-1] , freq[i-1])<<" "<<unique(freq[i-1], zeros)<<endl;
            if(unique(freq[l-1] , freq[i-1]) == unique(freq[i-1], zeros))
                ++splits;
        }
        return splits;
    }
    
    int unique(vector<int> &freq1, vector<int> &freq2) {
        int count = 0;
        for(int i = 0; i<26; i++)
            if(freq1[i] - freq2[i] > 0)
                ++count;
        return count;
    }
};