class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int groups = 0;
        unordered_map<int, set<int>> m;
        for(auto &it: reservedSeats) {
            if(it[1]!=1 || it[1]!=10)
            m[it[0]].insert(it[1]);
        }
        
        for(auto &iter: m) {
            int c1 = 1, c2 = 1, c3 = 1;
            int bitrep = 0;
            int i = iter.first;
            for(auto &it: m[i]) {
                bitrep += (1 << it);
            }
            int curr = 0;
            if((bitrep & 60) == 0) {
                ++curr;
            }
            if((bitrep & 960) == 0) {
                ++curr;
            }
            if(curr == 0 && (bitrep & 240) == 0) {
                ++curr;
            }
            groups+=curr;
        }
        return groups + 2*(n-m.size());
    }
};