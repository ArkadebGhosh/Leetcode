class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int high = nums[0];
        int low = nums[0];
        int n = nums.size();
        for(int i = 1; i<n; i++) {
            high+=nums[i];
            low = max(low, nums[i]);
        }
        
        while(low <= high) {
            int sum = 0;
            int sep = 0;
            int mid = (low+high)/2;
            for(int i = 0; i<n; i++) {
                if(sum+nums[i] > mid) {
                    ++sep;
                    sum = nums[i];
                }
                else
                    sum+=nums[i];
            }
            if(sep > m-1)
                low = mid + 1;
            else
                high = mid-1;
        }
        return low;
    }
};