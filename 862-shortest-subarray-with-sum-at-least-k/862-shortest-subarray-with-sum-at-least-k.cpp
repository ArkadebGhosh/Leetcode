class Solution {
public:
    int bin_search(vector<pair<long long int,int>> &arr, long long int k) {
        int low = 0;
        int high = arr.size()-1;
        while(low<=high) {
            int mid = (low + high)/2;
            if(arr[mid].first > k) {
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        if(high == -1)
            return -1;
        else
            return arr[high].second;
    }
    
    int shortestSubarray(vector<int>& nums, int k) {
        vector<pair<long long int, int>> allsum;
        long long int sum = 0;
        int n = nums.size();
        int ans = INT_MAX;
        for(int i = 0; i<n; i++) {
            sum+=nums[i];
            int idx = bin_search(allsum, sum - k);
            if(idx != -1) {
                ans = min(ans, i-idx);
            }
            else if(sum >= k) {
                    ans = min(ans, i+1);
            }
            while(allsum.size()!=0 && allsum.back().first >= sum) {
                allsum.pop_back();
            }
            allsum.push_back({sum, i});
        }
        if(ans == INT_MAX)
            return -1;
        return ans;
    }
};