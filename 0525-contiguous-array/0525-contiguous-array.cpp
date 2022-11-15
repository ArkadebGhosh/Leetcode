class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> m;
        int ones = 0;
        int zeros = 0;
        int ans = 0;
        int n = nums.size();
        m[0] = -1;
        for(int i = 0; i<n; i++) {
            if(nums[i] == 0)
                zeros++;
            else
                ones++;
            int diff = ones - zeros;
            if(m.count(diff) == 0)
                m[diff] = i;
            else {
                ans = max(ans, i - m[diff]);
            }
        }
        return ans;
    }
};