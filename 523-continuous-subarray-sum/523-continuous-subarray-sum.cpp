class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum = 0;
        unordered_map<int, int> m;
        m[0]=-1;
        for(int i = 0; i<nums.size(); i++) {
            sum += nums[i];
            if(m.count(sum%k) == 0)
            m[sum%k] = i;
            else {
                if(m[sum%k] != i-1)
                    return true;
            }
        }
        return false;
    }
};