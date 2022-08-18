class Solution {
public:
    static bool end(vector<int> v1, vector<int> v2) {
        return v1[1] < v2[1] || (v1[1] == v2[1] && v1[0] > v2[0]);
    }
    
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), end);
        
        int low = intervals[0][1]-1;
        int high = intervals[0][1];
        
        int s = 2;
        int n = intervals.size();
        for(int i = 1; i<n;i++) {
            // cout<<low<<" "<<high<<endl;
            if(intervals[i][0] <= low)
                continue;
            else if(intervals[i][0] > high) {
                s+=2;
                low = intervals[i][1] - 1;
                high = intervals[i][1];
            }
            else if(intervals[i][0] <= high && intervals[i][0] > low) {
                s+=1;
                low = high;
                high = intervals[i][1];
            }
        }
        return s;
    }
};