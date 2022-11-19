class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
       int n = nums.size();
        int mask = (int)pow(2, n) - 1;
        vector<vector<int>> ans;
        for(int i = 0; i<= mask; i++) {
            vector<int> subset;
            int j = 0;
            while((1 << j) <= i) {
                if((i & (1 << j)) != 0)
                    subset.push_back(nums[j]);
                j++;
            }
            ans.push_back(subset);
        }
        return ans;
    }
};