class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int miniK = -1;
        int maxiK = -1;
        int start = 0;
        int n = nums.size();
        long long ans = 0;
        for(int i = 0; i<n; i++) {
            if(nums[i] < minK || nums[i] > maxK) {
                start = i+1;
                miniK = i;
                maxiK = i;
                continue;
            }
            if(nums[i] == minK) {
                miniK = i;
            } 
            if(nums[i] == maxK) {
                maxiK = i;
            }
            // cout<<miniK<<" "<<maxiK<<endl;
            ans += (long long)((i - start + 1) - (i - min(maxiK, miniK)));
        }
        return ans;
    }
};