class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        unordered_map<int,int> memo;
        return comb(target, nums, memo);
    }
    
    int comb(int target, vector<int> &nums, unordered_map<int, int> &memo) {
        if(target == 0) {
            return 1;
        }
        int ans = 0;
        for(auto &it: nums) {
            if(target - it >= 0) {
                if(memo.count(target-it) > 0)
                    ans += memo[target-it];
                else
                    ans += comb(target-it, nums, memo);
            }     
        }
        memo[target] = ans;
        return ans;
    }
};