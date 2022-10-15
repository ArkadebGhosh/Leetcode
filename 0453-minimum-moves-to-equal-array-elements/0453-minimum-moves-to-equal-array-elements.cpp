class Solution {
public:
    int minMoves(vector<int>& nums) {
        int low = INT_MAX;
        int n = nums.size();
        for(int i = 0; i<n; i++) 
            low = min(low, nums[i]);
        int ans = 0;
        for(int i = 0; i<n; i++)
            ans+=(nums[i] - low);
        return ans;
    }
};