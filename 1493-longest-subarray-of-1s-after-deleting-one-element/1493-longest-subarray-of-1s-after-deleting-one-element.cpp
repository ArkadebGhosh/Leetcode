class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int ans = 0;
        int count = 0;
        int size = 0;
        for(int i = 0; i<n; i++) {
            if(nums[i] == 1)
                ++size;
            else if(nums[i] == 0)
                ++count;
            while(count > 1) {
                if(nums[start] == 0) {
                    --count;
                    size = i - start - 1;
                }
                ++start;
            }
            ans = max(ans, size);
        }
        if(count == 0)
            return ans - 1;
        return ans;
    }
};