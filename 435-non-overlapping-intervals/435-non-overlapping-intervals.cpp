class Solution {
public:
    static bool cmp(vector<int> &v1, vector<int> &v2) {
        return (v1[1] < v2[1]) || (v1[1] == v2[1] && v2[0] < v1[0]);
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int n = intervals.size();
        vector<vector<int>> temp;
        temp.push_back(intervals[0]);
        int ans = 1;
        for(int i = 1; i<n; i++) {
            if(intervals[i][0] >= (temp.back())[1]) {
                temp.push_back(intervals[i]);
            }
        }
        return n - temp.size();
    }
};