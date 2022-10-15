class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int sum = 0;
        int maxtime = INT_MIN;
        int start = 0, end = 0;
        int n = colors.size();
        int ans = 0;
        while(start < n) {
            if(end<n && colors[end] == colors[start]) {
                sum+=neededTime[end];
                maxtime = max(maxtime, neededTime[end]);
                ++end;
            }
            else if(end - start <= 1) {
                start = end;
                maxtime = INT_MIN;
                sum = 0;
            }
            else {
                // cout<<start<<" "<<end<<" "<<sum<<" "<<maxtime<<endl;
                ans += (sum - maxtime);
                sum = 0;
                start = end;
                maxtime = INT_MIN;
            }
        }
        return ans;
    }
};