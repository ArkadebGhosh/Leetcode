class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        bool odd = (n%2 != 0);
        for(int i = -n/2; i<=n/2; i++) {
            if(i == 0 && !odd)
                continue;
            ans.push_back(i);
        }
        return ans;
    }
};