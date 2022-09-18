class Solution {
public:
    static bool cmp(vector<int> &v1, vector<int> &v2) {
        return (v1[0] < v2[0]) || (v1[0] == v2[0] && v1[1] > v2[1]);
    }
    
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), cmp);
        vector<int> prev = intervals[0];
        int ans = 1;
        for(int i = 1; i<n; i++) {
            if(intervals[i][0] >= prev[0] && intervals[i][1] <= prev[1])
                continue;
            ++ans;
            prev = intervals[i];
        }
        return ans;
    }
};