#pragma GCC optimize("O1")
class Solution {
public:
    static bool cmp(vector<int> &v1, vector<int> &v2) {
        return (v1[0] < v2[0]) || (v1[0] == v2[0] && v1[1] < v2[1]);
    }
    
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), cmp);
        int n = events.size();
        vector<int> suffix(n, 0);
        suffix[n-1] = events[n-1][2];
        int ans = events[n-1][2];
        for(int i = n-2; i>=0; i--) {
            suffix[i] = max(suffix[i+1], events[i][2]);
        }
        
        for(int i = n-2; i>=0; i--) {
            int temp = events[i][2];
            int low = i+1;
            int high = n-1;
            int target = events[i][1]+1;
            
            while(low<=high) {
                int mid = (low+high)/2;
                if(events[mid][0] < target) {
                    low = mid+1;
                }
                else {
                    high = mid-1;
                }
            }
            
            int req_idx = low;
            if(req_idx == n) {
                ans = max(ans, events[i][2]);
                continue;
            }
            temp+=suffix[req_idx];
            ans = max(ans, temp);
        }
        return ans;
    }
};