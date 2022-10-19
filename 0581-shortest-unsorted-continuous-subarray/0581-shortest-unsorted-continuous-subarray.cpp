class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        // Sorting (O(nlogn))
        vector<int> copy = nums;
        sort(nums.begin(), nums.end());
        int start = -1;
        int end = -1;
        int n = nums.size();
        for(int i = 0; i<n; i++) {
            if(copy[i] != nums[i]) {
                start = i;
                break;
            }
        }
        
        for(int i = n-1; i>=0; i--) {
            if(copy[i] != nums[i]) {
                end = i;
                break;
            }
        }
        if(start == -1)
            return 0;
        return end - start + 1;
    }
};