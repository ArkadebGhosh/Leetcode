#pragma GCC optimize("O3")

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        vector<int> visited(nums.size(), 0);
        if(k==1)
            return true;
        int sum = 0;
        for(auto &it: nums)
            sum+=it;
        if(sum%k != 0)
            return false;
        sort(nums.begin(), nums.end(), greater<int>());
        return func(sum/k, sum/k, k, nums, visited, 0);
    }
    
    bool func(int remaining, int sum, int k, vector<int> &nums, vector<int> &visited, int start) {
        // cout<<remaining<<endl;
        if(k == 1)
            return true;
        if(start>=nums.size()) {
            // cout<<"triggered: "<<remaining<<endl;
            return false;
        }
            
        if(remaining == 0)
            return func(sum, sum, k-1, nums, visited, 0);
        for(int i = start; i<nums.size(); i++) {
            if(!visited[i] && nums[i] <= remaining) {
                visited[i] = 1;
                if(func(remaining-nums[i], sum, k, nums, visited, i+1))
                    return true;
                visited[i] = 0;
            }
        }
        return false;
    }
};