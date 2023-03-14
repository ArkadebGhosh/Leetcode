class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int c = 0;
        for(i = 0; i<n; i++) {
            if(nums[i] != 0 && i!=c) {
                nums[c++] = nums[i];
                nums[i] = 0;
            }
            else if(nums[i]!=0)
                ++c;
        }
    }
};