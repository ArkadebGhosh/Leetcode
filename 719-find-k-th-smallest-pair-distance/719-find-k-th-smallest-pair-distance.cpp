class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int low = 0;
        int high = nums[n-1] - nums[0];
        while(low <= high) {
            int req_diff = (low + high)/2;
            
            int start = 0;
            int end = 1;
            int count_pairs = 0;
            for(; end<n; end++) {
                while(nums[end] - nums[start] > req_diff) {
                    ++start;
                }
                if(start<end)
                count_pairs+=(end-start);
            }
            if(count_pairs < k) {
                low = req_diff + 1;
            }
            else {
                high = req_diff-1;
            }
        }
        return low;
    }
};