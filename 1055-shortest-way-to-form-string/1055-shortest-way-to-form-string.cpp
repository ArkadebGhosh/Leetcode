class Solution {
public:
    int shortestWay(string source, string target) {
        unordered_map<char, vector<int>> indices;
        int n = source.size();
        for(int i = 0; i<n; i++) {
            indices[source[i]].push_back(i);
        }
        
        int ans = 1;
        int pos = 0;
        for(int i = 0; i<target.size(); i++) {
            char curr = target[i];
            if(indices.count(curr) == 0)
                return -1;
            int foundidx = lower_bound(indices[curr].begin(), indices[curr].end(), pos) - indices[curr].begin();
            if(foundidx >= indices[curr].size()) {
                ++ans;
                pos = 0;
                --i;
            }
            else {
                pos = indices[curr][foundidx]+1;
            }
        }
        return ans;
    }
};