class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeros = 0;
        int ans = 0;
        int start = 0;
        int n = nums.size();
        for(int i = 0; i<n; i++) {
            if(nums[i] == 0)
                ++zeros;
            while(zeros > k) {
                if(nums[start] == 0)
                    --zeros;
                ++start;
            }
            ans = max(ans, i-start+1);
        }
        return ans;
    }
};