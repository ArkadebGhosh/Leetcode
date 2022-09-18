class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxleft(n, nums[0]);
        vector<int> minright(n, nums[n-1]);
        
        for(int i = 1; i<n; i++) {
            maxleft[i] = max(nums[i], maxleft[i-1]);
            minright[n-i-1] = min(nums[n-i-1], minright[n-i]);
        }
        
        for(int i = 0; i<n-1; i++) {
            if(maxleft[i] <= minright[i+1])
                return i+1;
        }
        return 0;
    }
};