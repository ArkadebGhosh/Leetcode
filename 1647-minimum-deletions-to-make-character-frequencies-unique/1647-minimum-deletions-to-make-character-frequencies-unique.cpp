class Solution {
public:
    int minDeletions(string s) {
        int l = s.size();
        vector<int>freq(26,0);
        for(int i = 0; i<l; i++)
            freq[s.at(i) - 'a']++;
        map<int, int> m;
        for(auto &it: freq) {
            if(!m.count(it))
                m[it] = 1;
            else
                m[it]+=1;
        }
        map<int, int>::reverse_iterator it;
        int deletions = 0;
        for(it = m.rbegin(); it!=m.rend(); it++) {
            int freq = it->first;
            int nchars = it->second;
            if(freq == 0)
                break;
            deletions += max(0, nchars - 1);
            m[freq-1] += max(0, nchars - 1);
        }
        return deletions;
    }
};