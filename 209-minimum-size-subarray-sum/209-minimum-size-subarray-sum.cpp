class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0, ans = INT_MAX, start = 0;
        for(int i = 0; i<nums.size(); i++) {
            sum+=nums[i];
            while(sum>=target) {
                sum-=nums[start];
                if(sum < target) 
                    ans = min(ans, i-start+1);
                start++;
            }
        }
        if(ans == INT_MAX)
            return 0;
        return ans;
    }
};