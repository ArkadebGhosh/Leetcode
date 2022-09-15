class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        sort(changed.begin(), changed.end());
        unordered_map<int, int> m;
        int zeroes = 0;
        if(n%2)
            return {};
        for(int i = 0; i<n; i++) {
            if(changed[i]!=0)
                m[changed[i]]+=1;
            else
                ++zeroes;
        }
        
        if(zeroes%2)
            return {};

        int count = zeroes;
        vector<int> ans(zeroes/2, 0);
        
        for(int i = 0; i<n; i++) {
            if(changed[i] == 0 || !m.count(changed[i]) || m[changed[i]] == 0)
                continue;
            if(m.count(changed[i]*2) && m[changed[i]*2]) {
                m[changed[i]*2]--;
                m[changed[i]]--;
                count+=2;
                ans.push_back(changed[i]);
            }
        }
        if(count!=n)
            return {};
        return ans;
    }
};